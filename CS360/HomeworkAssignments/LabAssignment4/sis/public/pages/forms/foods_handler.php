<?php

$conn = new mysqli("localhost", "root", "", "labassignment4");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$action = $_POST['action'];

$foodID = $_POST['foodID'];
$name = $_POST['name'];
$brand = $_POST['brand'];
$type = $_POST['type'];
$price = $_POST['price'];
$weight = $_POST['weight'];
$class = $_POST['classoffood'];

switch ($action) {
    case 'create':
        $stmt = $conn->prepare("INSERT INTO foods (FoodID, Name, Brand, TypeOfFood, Price, ItemWeight, ClassOfFood) VALUES (?, ?, ?, ?, ?, ?, ?)");
        $stmt->bind_param("isssdds", $foodID, $name, $brand, $type, $price, $weight, $class);
        $stmt->execute();
        echo "Food entry created successfully.";
        $stmt->close();
        break;

    case 'read':
        $stmt = $conn->prepare("SELECT * FROM foods");
        //$stmt->bind_param("i", $foodID);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($row = $result->fetch_assoc()) {
            echo "<pre>";
            print_r($row);
            echo "</pre>";
        } else {
            echo "No record found.";
        }
        $stmt->close();
        break;

    case 'update':
        $stmt = $conn->prepare("UPDATE foods SET Name = ?, Brand = ?, TypeOfFood = ?, Price = ?, ItemWeight = ?, ClassOfFood = ? WHERE FoodID = ?");
        $stmt->bind_param("sssddsi", $name, $brand, $type, $price, $weight, $class, $foodID);
        $stmt->execute();
        echo "Food entry updated.";
        $stmt->close();
        break;

    case 'delete':
        $stmt = $conn->prepare("DELETE FROM foods WHERE FoodID = ?");
        $stmt->bind_param("i", $foodID);
        $stmt->execute();
        echo "Food entry deleted.";
        $stmt->close();
        break;

    default:
        echo "Invalid action.";
}

if ($action) {
    echo ucfirst($action) . " attempt complete!";
    header("Location:foods_page.html");
    $conn->close(); 
    exit();
} else {
    echo "Error: " . $conn->error;
}
?>
