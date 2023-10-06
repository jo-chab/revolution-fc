<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc");    require_once '../vendor/ezyang/htmlpurifier/library/HTMLPurifier.auto.php'; // Include HTML Purifier		unset($_GET);        $zt_title = isset($_POST['zt_title']) ? nl2br(stripslashes($_POST['zt_title'])) : retour_erreur(51, 7);    $zt_intro = isset($_POST['zt_intro']) ? nl2br(stripslashes($_POST['zt_intro'])) : retour_erreur(51, 7);    $userHtml = isset($_POST['ta_prog']) ? $_POST['ta_prog'] : retour_erreur(51, 7);    $element = $_POST['element'];        // Create an HTML Purifier configuration    $config = HTMLPurifier_Config::createDefault();    $purifier = new HTMLPurifier($config);        // Clean and sanitize the HTML content    $cleanHtml = $purifier->purify($userHtml);        // Validate the length of the HTML content (adjust as needed)    $maxLength = 10000;    if (strlen($cleanHtml) > $maxLength) {        retour_erreur(11, 123); // Handle the error    }        // Define the valid file extensions    $extensions_valides = array('jpg', 'jpeg', 'png');    $page = '51';    $error_code = '1024';    if ($_FILES['f_photo_p']['size'] == 0)    {        $stmt = $db->prepare('UPDATE PROGRAMS SET program_name = ?, program_intro = ?, program_text = ? WHERE id_program = ?');        $execute = $stmt->execute([            addslashes($zt_title),            addslashes($zt_intro),            $cleanHtml,            $element        ]);        if ($execute) {            $stmt->closeCursor();            retour_erreur(51,3);        } else {            retour_erreur(51,4);        }    }    else    {        // Handle file upload        $dossier = "img/";        $destination = handleFileUpload($_FILES['f_photo_p'], $dossier, $extensions_valides, $page, $error_code);        $stmt = $db->prepare('UPDATE PROGRAMS SET program_name = ?, program_intro = ?, program_text = ?, program_img = ? WHERE id_program = ?');        $execute = $stmt->execute([            addslashes($zt_title),            addslashes($zt_intro),            $cleanHtml,            $destination,            $element        ]);        if ($execute) {            $stmt->closeCursor();            retour_erreur(51,3);        } else {            retour_erreur(51,4);        }    }?>