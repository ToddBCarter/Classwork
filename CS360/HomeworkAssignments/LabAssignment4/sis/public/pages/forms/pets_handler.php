<?php

//Connect to DB
$conn = new mysqli("localhost", "root", "", "labassignment4");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

//Values from pets_page.html
$action = $_POST['action'] ?? '';
$petID = $_POST['petID'] ?? '';
$petname = $_POST['petname'] ?? '';
$age = $_POST['age'] ?? '';
$street = $_POST['street'] ?? '';
$city = $_POST['city'] ?? '';
$zipcode = $_POST['zipcode'] ?? '';
$state = $_POST['state'] ?? '';
$typeofpet = $_POST['typeofpet'] ?? '';


switch ($action) {
    case 'create':
        //Create a GUID for pet
        //$NewID = GUID();
        //Though the GUIDs work, for the sake of simplicity in this assignment, user-inputted IDs are used instead.
        //Otherwise connecting owners with pets in the owns table would be madness.

        //Insert new pet with values from form
        $sql = "INSERT INTO pets (PetID, Name, Age, Street, City, ZipCode, State, TypeofPet) 
                VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

        //Using bind_param() for input sanitizing.  This turns all inputs into data, which is
        //processed more safely by SQL.
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("ssississ", $petID, $petname, $age, $street, $city, $zipcode, $state, $typeofpet);
        $stmt->execute();
        echo "Pet created successfully!";

        break;

    case 'read':
        //Display pets by ID
        $sql = "SELECT * FROM Pets";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($row = $result->fetch_assoc()) {
            echo "<pre>";
            print_r($row);
            echo "</pre>";
        } else {
            echo "No pets found with that ID.";
        }

        break;

    case 'update':
        //Update pet
        $sql = "UPDATE Pets SET Name = ?, Age=?, Street=?, City=?, ZipCode=?, State=?, TypeofPet=? WHERE PetID=?";

        $stmt = $conn->prepare($sql);
        $stmt->bind_param("sississs", $petname, $age, $street, $city, $zipcode, $state, $typeofpet, $petID);
        $stmt->execute();

        echo "Pet updated successfully.";

        break;

    case 'delete':
        //Delete pet
        $sql = "DELETE FROM Pets WHERE PetID=?";

        $stmt = $conn->prepare($sql);
        $stmt->bind_param("s", $petID);
        $stmt->execute();

        echo "Pet deleted successfully.";

        break;

    default:
        echo "Invalid action.";
        exit;
}

//$result = $conn->query($sql);

if ($action) {
    echo ucfirst($action) . " attempt complete!!";
    header("Location:pets_page.php");
    exit();
} else {
    echo "Error: " . $conn->error;
}

$conn->close();


function GUID()
{
    if (function_exists('com_create_guid') === true)
    {
        //It says this is wrong, but it still works, so w/e
        return trim(com_create_guid(), '{}');
    }

    return sprintf('%04X%04X-%04X-%04X-%04X-%04X%04X%04X', mt_rand(0, 65535), mt_rand(0, 65535), mt_rand(0, 65535), mt_rand(16384, 20479), mt_rand(32768, 49151), mt_rand(0, 65535), mt_rand(0, 65535), mt_rand(0, 65535));
}
?>
