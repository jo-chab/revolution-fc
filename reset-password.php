<?php
    include("_includes/session_test.inc");
    include("_includes/_revolutionfc.inc");
?>
    <!doctype html>
    <html>
<head>
    <meta charset="UTF-8">
    <title>RFC - PWS reset</title>
    
    <?php
        include("_includes/head.inc");
        echo "<body>";
        include("_includes/header.inc");
    ?>
    
    
    <section>
        
        
        <?php
            require '_revolutionfc.inc'; // Include your database connection file
            
            // Extract the token from the URL (assuming it's passed as a GET parameter)
            $resetToken = $_GET['token'];
            
            // Verify the token's validity and retrieve the associated user ID
            function verifyTokenAndGetUserId($token)
            {
                global $db;
                
                $token = $db->quote($token);
                $sql = "SELECT user_id FROM password_reset_tokens WHERE token = $token AND expires_at >= NOW()";
                $stmt = $db->query($sql);
                
                if ($stmt->rowCount() === 1) {
                    $row = $stmt->fetch(PDO::FETCH_ASSOC);
                    return $row['user_id'];
                } else {
                    return null; // Token not found or expired
                }
            }
            
            // Check if the token is valid
            $user_id = verifyTokenAndGetUserId($resetToken);
            
            if ($user_id !== null) {
                // Token is valid, show the password reset form
                if ($_SERVER['REQUEST_METHOD'] === 'POST') {
                    // Handle form submission
                    $newPassword = $_POST['new_password'];
                    
                    // Hash the new password
                    $hashedPassword = password_hash($newPassword, PASSWORD_DEFAULT);
                    
                    // Update the user's password in the USERS table
                    $sqlUpdate = "UPDATE USERS SET password = :password WHERE id_user = :user_id";
                    $stmtUpdate = $db->prepare($sqlUpdate);
                    $stmtUpdate->bindParam(':password', $hashedPassword, PDO::PARAM_STR);
                    $stmtUpdate->bindParam(':user_id', $user_id, PDO::PARAM_INT);
                    
                    if ($stmtUpdate->execute()) {
                        // Password reset successful, delete the token
                        $sqlDelete = "DELETE FROM password_reset_tokens WHERE token = $resetToken";
                        $db->exec($sqlDelete);
                        echo '<div class="message-box fade-out"><div class="icon i-alert"></div><p>Password reset successful. You can now log in with your new password.</p></div>';
                    } else {
                        echo '<div class="message-box fade-out"><div class="icon i-alert"></div><p>Error updating the password.</p></div>';
                    }
                } else {
                    // Display the password reset form
                    ?>
                    <html>
                    <body>
                    <form method="post" action="">
                        <label for="new_password">New Password:</label>
                        <input type="password" name="new_password" id="new_password" required>
                        <input type="submit" value="Reset Password">
                    </form>
                    </body>
                    </html>
                    <?php
                }
            } else {
                echo '<div class="message-box fade-out"><div class="icon i-alert"></div><p>Invalid or expired token. Please request a new password reset.</p></div>';
            }
        ?>
    
    
    </section>

<?php include("_includes/footer.inc") ?>