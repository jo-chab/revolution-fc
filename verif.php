<?php
	session_start();
	include("_includes/_revolutionfc.inc");
	if(!empty($_GET) && !empty($_GET['hash']))
	{
		extract($_GET);
	}
	else
	{
		header('Location: https://www.revolutionfc.ca/');
	}

	$email=$_GET['email'];
	$hash=$_GET['hash'];

	$stmt = $db->prepare("Select * FROM USERS WHERE email = ? AND hash = ? ");
    $stmt->execute([$email,$hash]);

    while ($result = $stmt->fetch());
	{
		extract($result);

		if ($actif==1)
		{
			header('Location: https://www.revolutionfc.ca/admin/login.php?m=7');
		}
		else
		{
			$change = 1;
			$stmt2 = $db->prepare("UPDATE USERS SET actif='$change' WHERE email = ? AND hash = ? ");
            $execute2 = $stmt2->execute([
                $email,
                $hash
            ]);
			if ($execute2)
			{
                $stmt->closeCursor();
				header('Location: https://www.revolutionfc.ca/admin/login.php?m=8');
			}
			else {
				header('Location: https://www.revolutionfc.ca/admin/login.php?m=9');
			}
		}		
	}

	
	
?>