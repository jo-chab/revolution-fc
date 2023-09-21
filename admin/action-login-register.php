<?php	include("../_includes/_revolutionfc.inc");		function post_captcha($user_response)	{		$fields_string = '';		$fields = array(			'secret' => '6Lc8qswcAAAAAMxTldJHIjvjJsxjLA7f_oSNZi6X',			'response' => $user_response		);		foreach ($fields as $key => $value) {			$fields_string .= $key . '=' . $value . '&';		}		$fields_string = rtrim($fields_string, '&');				$ch = curl_init();		curl_setopt($ch, CURLOPT_URL, 'https://www.google.com/recaptcha/api/siteverify');		curl_setopt($ch, CURLOPT_POST, count($fields));		curl_setopt($ch, CURLOPT_POSTFIELDS, $fields_string);		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);				$result = curl_exec($ch);		curl_close($ch);				return json_decode($result, true);	}		// Verify reCAPTCHA	$captcha_response = $_POST['g-recaptcha-response'];	$captcha_result = post_captcha($captcha_response);		if (!$captcha_result['success']) {		// reCAPTCHA verification failed		header('Location: login.php?error=captcha');		exit();	}		// Validate and sanitize user inputs	$login = filter_var($_POST['zt_username'], FILTER_SANITIZE_STRING);	$email = filter_var($_POST['zt_email'], FILTER_SANITIZE_EMAIL);	$pass1 = $_POST['zt_new_pass'];	$pass2 = $_POST['zt_new_pass_2'];	$prenom = filter_var($_POST['zt_fn'], FILTER_SANITIZE_STRING);	$nom = filter_var($_POST['zt_ln'], FILTER_SANITIZE_STRING);		// Check if the email is already in use	if (verif_email($db, $email) !== -1) {		header('Location: https://www.revolutionfc.ca/admin/login?m=3');		exit();	}		// Check if passwords match	if ($pass1 !== $pass2) {		header('Location: https://www.revolutionfc.ca/admin/login?m=4');		exit();	}		// Hash the password securely	$pass3 = password_hash($pass1, PASSWORD_BCRYPT);		// Generate a unique hash for email verification	$hash = md5(uniqid());		// Set initial user status as inactive (0) and type (1) - Adjust as needed	$actif = "0";	$type = "1";		$stmt2 = $db->prepare('INSERT INTO USERS (user_fn, user_ln, login, password, email, hash, actif, type) VALUES (?, ?, ?, ?, ?, ?, ?, ?)');	$execute = $stmt2->execute([		$prenom,		$nom,		$login,		$pass3,		$email,		$hash,		$actif,		$type	]);		if ($execute) {		$stmt2->closeCursor();		envoi_email($login, $pass1, $email, $hash, $prenom, $nom);		header('Location: https://www.revolutionfc.ca/admin/login?m=1');	} else {		header('Location: https://www.revolutionfc.ca/admin/login?m=4');	}		function verif_email($db, $email)	{		$stmt3 = $db->prepare("SELECT email FROM USERS WHERE email = ?");		$stmt3->execute([$email]);		$result = $stmt3->fetch(PDO::FETCH_ASSOC);		if ($result) {			return $result['email'];		} else {			return -1;		}	}		function envoi_email($param1, $param2, $param3, $param4, $param5, $param6)	{		$destinataire="moustapha.sall@revolutionfc.ca";		$destinataire2=$param3;		$prenom=$param5;		$nom=$param6;		$objet = "Revolution FC - Nouvel utilisateur inscrit";		$objet2 = "Revolution FC - Confirmation inscription utilisateur";		$contenu = "							Un nouvel utilisateur s'est inscrit depuis votre site internet<br /><br />							Prenom : $prenom<br />							Nom : $nom<br />							Login : $param1<br />							Adresse courriel : $param3<br />				";		$contenu2 = "							Merci pour votre inscription depuis notre site Revolutionfc.ca<br />							Vous pourrez vous connecter sur le site après avoir cliqué sur le lien d'activation ci-dessous.<br />							<a href='https://www.revolutionfc.ca/verif.php?email=".$param3."&hash=".$param4."'>https://www.revolutionfc.ca/verif.php?email=$param3&hash=$param4</a>							Voici vos identifiants, nous vous recommandons de les garder précieusmeent.<br /><br />							Login : $param1<br />							Mot de passe : $param2<br />							Adresse courriel : $param3<br />				";		$entetes =			"Content-type: text/html; charset=utf-8" . "\r\n" .			"From: jonathan@chabertdesign.com" . "\r\n" .			"Reply-To: jonathan@chabertdesign.com" . "\r\n" .			"X-Mailer: PHP/" . phpversion();				mail($destinataire, $objet, $contenu, $entetes);		mail($destinataire2, $objet2, $contenu2, $entetes);	}?>