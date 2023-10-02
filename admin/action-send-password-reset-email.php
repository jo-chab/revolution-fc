<?php        require '../_includes/_revolutionfc.inc'; // Include your database connection setup    require '../vendor/autoload.php'; // Include the PHPMailer library        // Function to send a password reset email    function sendPasswordResetEmail($email, $resetLink)    {        // Create a PHPMailer instance        $mail = new PHPMailer\PHPMailer\PHPMailer();        $mail->IsSMTP();        $mail->SMTPAuth = true;        $mail->SMTPSecure = 'tls';        $mail->Host = 'mail.chabertdesign.com'; // SMTP server (replace with your SMTP server)        $mail->Port = 465; // SMTP port (replace with your SMTP port)        $mail->Username = 'chabe642'; // SMTP username (replace with your SMTP username)        $mail->Password = '2000ndGLR!'; // SMTP password (replace with your SMTP password)        $mail->setFrom('info@chabertdesign.com', 'Revolution FC');        $mail->addAddress($email); // Recipient        $mail->Subject = 'Password Reset admin';        $mail->isHTML(true);                // Email content        $mail->Body = 'Click the following link to reset your password: <a href="' . $resetLink . '">Reset Password</a>';                if ($mail->send()) {            return true; // Email sent successfully        } else {            return false; // Email sending failed        }    }        // Implement the generateUniqueToken function    function generateUniqueToken($email)    {        global $db;        $token = bin2hex(random_bytes(32)); // Generate a random token        $email = $db->quote($email);                // Insert the token and associate it with the user's email in the database        $sql = "INSERT INTO password_reset_tokens (email, token) VALUES ($email, '$token')";        $db->exec($sql);                return $token;    }// Check if an email parameter was provided in the POST request    if (isset($_POST['email'])) {        $userEmail = $_POST['email'];                // Generate a unique token        $resetToken = generateUniqueToken($userEmail);                if ($resetToken) {            // Construct the reset link            $resetLink = 'https://revolutionfc.ca/reset-password.php?token=' . $resetToken;                        // Send the password reset email            if (sendPasswordResetEmail($userEmail, $resetLink)) {                // Return a JSON success response                echo json_encode(['success' => true]);                http_response_code(200); // HTTP 200 OK            } else {                // Return a JSON error response                echo json_encode(['success' => false]);                http_response_code(500); // HTTP 500 Internal Server Error            }        } else {            // Failed to generate a token, return an error response            echo json_encode(['success' => false]);            http_response_code(500); // HTTP 500 Internal Server Error        }    } else {        // Email parameter is missing, return an error response        echo json_encode(['success' => false]);        http_response_code(400); // HTTP 400 Bad Request    }?>