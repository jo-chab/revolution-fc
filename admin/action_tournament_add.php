<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc");            unset($_GET);        // Check if required fields are set    if (isset($_POST['zt_name']) && isset($_POST['zt_intro']) && isset($_POST['ta_tournoi'])) {        $name = nl2br(stripslashes($_POST['zt_name']));        $desc = nl2br(stripslashes($_POST['zt_intro']));        $text = nl2br(stripslashes($_POST['ta_tournoi']));    } else {        retour_erreur(81, 7);    }        $actif = 0;        // Define the valid file extensions    $extensions_valides = array('jpg', 'jpeg', 'png');    $page = '81';    $error_code = '1024';        // Handle file upload    $dossier = "img/_tournoi/";    $destination = handleFileUpload($_FILES['f_photo_tournoi'], $dossier, $extensions_valides, $page, $error_code);        $stmt = $db->prepare('INSERT into TOURNAMENT (tournament_name, tournament_desc, tournament_text, tournament_img, actif) VALUES (?, ?, ?, ?, ?)');    $execute = $stmt->execute([        addslashes($name),        addslashes($desc),        addslashes($text),        $destination,        $actif    ]);        if ($execute) {        $stmt->closeCursor();        retour_erreur(81, 801);    } else {        retour_erreur(81, 802);    }?>