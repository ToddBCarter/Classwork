<?php

//Connect to DB
$conn = new mysqli("localhost", "root", "", "labassignment4");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

//Get data from owners_page.html
$ownerID = $_POST['ownerID'] ?? '';
$lastname = $_POST['lastname'] ?? '';
$street = $_POST['street'] ?? '';
$city = $_POST['City'] ?? '';
$zipcode = $_POST['zipcode'] ?? '';
$state = $_POST['State'] ?? '';
$age = $_POST['Age'] ?? '';
$income = $_POST['AnnualIncome'] ?? '';
$action = $_POST['action'] ?? '';

//Essentially the same functionality as pets_handler.php, but for the owners table
switch ($action) {
    case 'create':
        $sql = "INSERT INTO owners (OID, LastName, Street, City, ZipCode, State, Age, AnnualIncome)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("ssssisii", $ownerID, $lastname, $street, $city, $zipcode, $state, $age, $income);
        $stmt->execute();
        echo "Owner created successfully!";
        break;

    case 'read':
        $sql = "SELECT * FROM owners";
        $stmt = $conn->prepare($sql);
        //$stmt->bind_param("s", $ownerID);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($row = $result->fetch_assoc()) {
            echo "<pre>";
            print_r($row);
            echo "</pre>";
        } else {
            echo "No owner found with that ID.";
        }
        break;

    case 'update':
        $sql = "UPDATE owners SET LastName=?, Street=?, City=?, ZipCode=?, State=?, Age=?, AnnualIncome=? WHERE OID=?";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("sssisiis", $lastname, $street, $city, $zipcode, $state, $age, $income, $ownerID);
        $stmt->execute();
        echo "Owner updated successfully!";
        break;

    case 'delete':
        $sql = "DELETE FROM owners WHERE OID = ?";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("s", $ownerID);
        $stmt->execute();
        echo "Owner deleted successfully!";
        break;

    default:
        echo "Invalid action.";
        break;
}

if ($action) {
    echo ucfirst($action) . " attempt complete!!";
    header("Location:owners_page.html");
    exit();
} else {
    echo "Error: " . $conn->error;
}

$conn->close();
?>
