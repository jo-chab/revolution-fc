<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc");		unset($_GET);            // Check if all the required POST parameters are set    $requiredFields = ['zt_title', 'zt_desc'];    foreach ($requiredFields as $field) {        if (!isset($_POST[$field])) {            retour_erreur(301, 23);        }    }        $zt_title = nl2br(stripslashes($_POST['zt_title']));    $zt_desc = nl2br(stripslashes($_POST['zt_desc']));    $element = $_POST['element'];    if ($_FILES['f_document']['size'] == 0) {        $stmt = $db->prepare('UPDATE EMPLOIS SET job_name = ?, job_desc = ? WHERE id_job = ?');        $execute = $stmt->execute([addslashes($zt_title), addslashes($zt_desc), $element]);        if ($execute) {            $stmt->closeCursor();            retour_erreur(301,3);        } else {            retour_erreur(301,4);        }    }    else {                // Define the valid file extensions        $page = '301';                // Handle file upload        $dossier = "docs/emplois";        $destination = handleDocUpload($_FILES['f_document'], $dossier, $page);        $stmt = $db->prepare('UPDATE EMPLOIS SET job_name = ?, job_desc = ?, job_doc = ? WHERE id_job = ?');        $execute = $stmt->execute([addslashes($zt_title), addslashes($zt_desc), $destination, $element]);        if ($execute) {            $stmt->closeCursor();            retour_erreur(301,3);        } else {            retour_erreur(301,4);        }    }?>