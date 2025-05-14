<?php

$conn = new mysqli("localhost", "root", "", "labassignment4");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$petID = $_POST['petID'] ?? '';
$year = $_POST['year'] ?? '';
$ownerID = $_POST['OID'] ?? '';
$age = $_POST['age'] ?? '';
$price = $_POST['price'] ?? '';
$action = $_POST['action'] ?? '';

switch ($action) {
    case 'create':
        //First, check if the PetID exists in the pets table
        $stmt_pet = $conn->prepare("SELECT 1 FROM pets WHERE PetID = ?");
        $stmt_pet->bind_param("s", $petID);
        $stmt_pet->execute();
        $result_pet = $stmt_pet->get_result();
        
        //Next, check if the OwnerID exists in the owners table
        $stmt_owner = $conn->prepare("SELECT 1 FROM owners WHERE OID = ?");
        $stmt_owner->bind_param("s", $ownerID);
        $stmt_owner->execute();
        $result_owner = $stmt_owner->get_result();

        //If both IDs exist in their tables, proceed with insert
        if ($result_pet->num_rows > 0 && $result_owner->num_rows > 0) {
            $stmt_insert = $conn->prepare("INSERT INTO owns (PetID, Year, OID, PetAgeatOwnership, PricePaid) VALUES (?, ?, ?, ?, ?)");
            $stmt_insert->bind_param("sisii", $petID, $year, $ownerID, $age, $price);
            if ($stmt_insert->execute()) {
                echo "Ownership record created successfully.";
            } else {
                echo "Error inserting ownership record: " . $stmt_insert->error;
            }
            $stmt_insert->close();
        } else {
            echo "Insertion failed: ";
            if ($result_pet->num_rows === 0) echo "PetID not found. ";
            if ($result_owner->num_rows === 0) echo "OwnerID not found.";
        }
    
        $stmt_pet->close();
        $stmt_owner->close();
        break;



    case 'read':
        $stmt = $conn->prepare("SELECT * FROM owns");
        //$stmt->bind_param("ss", $petID, $ownerID);
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
        $stmt = $conn->prepare("UPDATE owns SET Year = ?, PetAgeatOwnership = ?, PricePaid = ? WHERE PetID = ? AND OID = ?");
        $stmt->bind_param("iidsi", $year, $age, $price, $petID, $ownerID);
        if ($stmt->execute()) {
            echo "Record updated successfully.";
        } else {
            echo "Error updating record: " . $stmt->error;
        }
        $stmt->close();
        break;

    case 'delete':
        $stmt = $conn->prepare("DELETE FROM owns WHERE PetID = ? AND OID = ?");
        $stmt->bind_param("ss", $petID, $ownerID);
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
    header("Location:owns_page.html");
    $conn->close(); 
    exit();
} else {
    echo "Error: " . $conn->error;
}
?>
