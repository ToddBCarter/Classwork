<?php

$conn = new mysqli("localhost", "root", "", "labassignment4");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$ownerID = $_POST['ownerID'] ?? '';
$foodID = $_POST['foodID'] ?? '';
$petID = $_POST['petID'] ?? '';
$month = $_POST['month'] ?? '';
$year = $_POST['year'] ?? '';
$quantity = $_POST['quantity'] ?? '';
$action = $_POST['action'] ?? '';

switch ($action) {
    case 'create':

        //First, check if the OwnerID exists in the owners table
        $stmt_owner = $conn->prepare("SELECT 1 FROM owners WHERE OID = ?");
        $stmt_owner->bind_param("s", $ownerID);
        $stmt_owner->execute();
        $result_owner = $stmt_owner->get_result();
        
        //Next, check if the Food exists in the foods table
        $stmt_food = $conn->prepare("SELECT 1 FROM foods WHERE FoodID = ?");
        $stmt_food->bind_param("s", $foodID);
        $stmt_food->execute();
        $result_food = $stmt_food->get_result();

        //Next, check if the PetID exists in the pets table
        $stmt_pet = $conn->prepare("SELECT 1 FROM pets WHERE PetID = ?");
        $stmt_pet->bind_param("s", $petID);
        $stmt_pet->execute();
        $result_pet = $stmt_pet->get_result();
        

        //If all three IDs exist in their tables, proceed with insert
        if ($result_pet->num_rows > 0 && $result_owner->num_rows > 0 && $result_food->num_rows) {

            $stmt_insert = $conn->prepare("INSERT INTO purchases (OID, FoodID, PetID, Month, Year, Quantity) VALUES (?, ?, ?, ?, ?, ?)");
            $stmt_insert->bind_param("sssiii", $ownerID, $foodID, $petID, $month, $year, $quantity);

            if ($stmt_insert->execute()) {
                echo "Purchase record created successfully.";
            } else {
                echo "Error inserting purchase record: " . $stmt_insert->error;
            }
            $stmt_insert->close();
        } else {
            echo "Insertion failed: ";
            if ($result_pet->num_rows === 0) echo "PetID not found. ";
            if ($result_owner->num_rows === 0) echo "OwnerID not found.";
            if ($result_food->num_rows === 0) echo "FoodID not found.";
        }
    
        $stmt_pet->close();
        $stmt_owner->close();
        $stmt_food->close();
        break;


    case 'read':
        $stmt = $conn->prepare("SELECT * FROM purchases");
        $stmt->execute();
        $result = $stmt->get_result();
        if ($result->num_rows > 0) {
            echo "<pre>";
            while ($row = $result->fetch_assoc()) {
                print_r($row);
            }
            echo "</pre>";
        } else {
            echo "No records found.";
        }
        $stmt->close();
        break;


    case 'update':
        $stmt = $conn->prepare("UPDATE owns SET Year = ?, PetAgeatOwnership = ?, PricePaid = ? WHERE PetID = ? AND OID = ? AND FoodID = ?");
        $stmt->bind_param("iidsi", $year, $age, $price, $petID, $ownerID, $foodID);
        if ($stmt->execute()) {
            echo "Record updated successfully.";
        } else {
            echo "Error updating record: " . $stmt->error;
        }
        $stmt->close();
        break;


    case 'delete':
        $stmt = $conn->prepare("DELETE FROM owns WHERE PetID = ? AND OID = ? AND FoodID = ?");
        $stmt->bind_param("sss", $petID, $ownerID, $foodID);
        if ($stmt->execute()) {
            echo "Record deleted successfully.";
        } else {
            echo "Error deleting record: " . $stmt->error;
        }
        $stmt->close();
        break;

    default:
        echo "Invalid action.";
        break;
}

if ($action) {
    echo ucfirst($action) . " attempt complete!";
    header("Location:purchases_page.html");
    $conn->close(); 
    exit();
} else {
    echo "Error: " . $conn->error;
}
?>
