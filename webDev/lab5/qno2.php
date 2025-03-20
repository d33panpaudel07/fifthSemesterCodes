<?php
// Check if form was submitted
if (isset($_POST["submit"])) {
    $targetDir = "uploads/";  // Directory where files will be stored
    $targetFile = $targetDir . basename($_FILES["fileToUpload"]["name"]);
    $uploadOk = 1;
    $fileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));
    
    // Create uploads directory if it doesn't exist
    if (!file_exists($targetDir)) {
        mkdir($targetDir, 0777, true);
    }

    // Check file size (example: max 5MB)
    if ($_FILES["fileToUpload"]["size"] > 5000000) {
        $message = "Sorry, your file is too large.";
        $uploadOk = 0;
    }

    // Allow certain file formats
    $allowedTypes = array("jpg", "png", "pdf", "txt");
    if (!in_array($fileType, $allowedTypes)) {
        $message = "Sorry, only JPG, PNG, PDF & TXT files are allowed.";
        $uploadOk = 0;
    }

    // Check if file already exists
    if (file_exists($targetFile)) {
        $message = "Sorry, file already exists.";
        $uploadOk = 0;
    }

    // Check if $uploadOk is set to 0 by an error
    if ($uploadOk == 0) {
        $messageClass = "error";
    } else {
        // Try to upload file
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $targetFile)) {
            $message = "The file " . htmlspecialchars(basename($_FILES["fileToUpload"]["name"])) . " has been uploaded.";
            $messageClass = "success";
        } else {
            $message = "Sorry, there was an error uploading your file.";
            $messageClass = "error";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload Result</title>
    <link rel="stylesheet" href="styles.css"> <!-- You can use the same CSS as above -->
</head>
<body>
    <div class="upload-container">
        <h2>Upload Result</h2>
        <?php if (isset($message)): ?>
            <div class="message <?php echo $messageClass; ?>">
                <?php echo $message; ?>
            </div>
        <?php endif; ?>
        <p><a href="upload.html">Upload another file</a></p>
    </div>
</body>
</html>