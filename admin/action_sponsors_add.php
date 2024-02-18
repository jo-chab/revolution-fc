<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc"); // Include the file with the handleFileUpload function		unset($_GET);        // Check if required POST parameters are set    $zt_nom = isset($_POST['zt_nom']) ? nl2br(stripslashes($_POST['zt_nom'])) : '';    $zt_site = isset($_POST['zt_site']) ? nl2br(stripslashes($_POST['zt_site'])) : '';        // Validate inputs (e.g., check for required fields, sanitize data).    if (empty($zt_nom) || empty($zt_site)) {        retour_erreur(91, 7);    }        // Define the valid file extensions    $extensions_valides = array('jpg', 'jpeg', 'png', 'svg');    // Handle file upload    $dossier = "/img/_sponsors/";    $destination = handleFileUpload($_FILES['f_logo_img'], $dossier, $extensions_valides, '91', '1025');    $stmt2 = $db->prepare('INSERT INTO SPONSORS (name_sponsors, logo_sponsors, url) VALUES (?, ?, ?)');    $execute = $stmt2->execute([        $zt_nom,        $destination,        $zt_site    ]);    if ($execute) {        $stmt2->closeCursor();        retour_erreur(91,901);    } else {        retour_erreur(91,902);    }?>