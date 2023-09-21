<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc"); // Include the file with the handleFileUpload function        unset($_GET);        // Check if the required POST parameters are set    $requiredFields = ['zt_name', 'zt_function'];        foreach ($requiredFields as $field) {        if (!isset($_POST[$field])) {            retour_erreur(25, 7);        }    }        $name = nl2br(stripslashes($_POST['zt_name']));    $legend = nl2br(stripslashes($_POST['zt_desc']));    $email = nl2br(stripslashes($_POST['zt_email']));    $function = nl2br(stripslashes($_POST['zt_function']));        $element = $_POST['element'];        // Define the valid file extensions    $extensions_valides = array('jpg', 'jpeg', 'png');    $page = '25';    $error_code = '1024';            if ($_FILES['f_ppl_img']['size'] == 0) {                // If no new image is uploaded, update the other fields without changing the image column        $stmt = $db->prepare('UPDATE MEMBERS_STAFF SET member_function = ?, member_name = ?, member_legend = ?, member_email = ? WHERE id_member = ?');        $execute = $stmt->execute([            $function,            $name,            $legend,            $email,            $element        ]);                if ($execute) {            $stmt->closeCursor();            retour_erreur(25, 3);        } else {            retour_erreur(25, 4);        }            } else {        // Handle file upload        $dossier="img/_people/";        $destination = handleFileUpload($_FILES['f_ppl_img'], $dossier, $extensions_valides, $page, $error_code);                $stmt = $db->prepare('UPDATE MEMBERS_STAFF SET member_function = ?, member_name = ?, member_legend = ?, member_email = ?, member_img = ? WHERE id_member = ?');        $execute = $stmt->execute([            $function,            $name,            $legend,            $email,            $destination,            $element        ]);                if ($execute) {            $stmt->closeCursor();            retour_erreur(25, 3);        } else {            retour_erreur(25, 4);        }    }?>