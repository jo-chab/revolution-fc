<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        $element = $_POST['element'];            // Construct the folder path    $folderPath = $_SERVER['DOCUMENT_ROOT'] . "/img/_albums/{$element}";        // Check if the folder exists and delete it    if (file_exists($folderPath)) {        if (!rmdir($folderPath)) {            // Error deleting folder            retour_erreur(66, 665); // or any appropriate error code        }    } else {        // Folder not found        retour_erreur(66, 667); // or any appropriate error code    }        // Delete all records from the 'ALBUMS' table where 'id_album' matches the given element    $stmt2 = $db->prepare("DELETE FROM ALBUMS WHERE id_album = ?");    $execute = $stmt2->execute([$element]);        // Delete all records from the 'ALBUMS_images' table where 'image_album' matches the given element    $stmt3 = $db->prepare("DELETE FROM ALBUMS_images WHERE image_album = ?");    $execute2 = $stmt3->execute([$element]);        // Check if both deletions were successful    if ($execute && $execute2) {        retour_erreur(66, 1);    } else {        retour_erreur(66, 2);    }?>