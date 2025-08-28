<?php
require '_functions.php';
$conn = db_connect();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Sanitize input for HTML output (not for SQL)
    $name = htmlspecialchars($_POST['name']);
    $email = htmlspecialchars($_POST['email']);
    $message = htmlspecialchars($_POST['message']);

    // Prepare statement to prevent SQL injection
    $stmt = $conn->prepare("INSERT INTO feedback (name, email, message) VALUES (?, ?, ?)");

    if ($stmt) {
        $stmt->bind_param("sss", $name, $email, $message);

        if ($stmt->execute()) {
            echo "<script>alert('Thank you for your feedback!'); window.location.href='../../index.php';</script>";
        } else {
            echo "<script>alert('Failed to submit feedback. Please try again later.'); window.location.href='../../index.php';</script>";
        }

        $stmt->close();
    } else {
        echo "<script>alert('Database error. Please try again later.'); window.location.href='../../index.php';</script>";
    }

    $conn->close();
}
?>

