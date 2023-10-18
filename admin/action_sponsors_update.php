<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc");        // Check if the form is submitted and contains the required fields.    if ($_SERVER['REQUEST_METHOD'] === 'POST') {        $zt_nom = isset($_POST['zt_nom']) ? nl2br(stripslashes($_POST['zt_nom'])) : null;        $zt_site = isset($_POST['zt_site']) ? nl2br(stripslashes($_POST['zt_site'])) : null;        $club = isset($_POST['ld_club']) ? $_POST['ld_club'] : null;        $summer = isset($_POST['ld_tournoi_summer']) ? $_POST['ld_tournoi_summer'] : null;        $winter = isset($_POST['ld_tournoi_winter']) ? $_POST['ld_tournoi_winter'] : null;        $element = isset($_POST['element']) ? $_POST['element'] : null;                // Validate inputs (e.g., check for required fields, sanitize data).        if (empty($zt_nom) || empty($zt_site) || $club === null || $summer === null || $winter === null || $element === null) {            retour_erreur(91, 7);        }                        // Define the valid file parameters        $extensions_valides = array('jpg', 'jpeg', 'png', 'svg');        $dossier = "/img/_sponsors/";                $stmt = $db->prepare("SELECT logo_sponsors FROM SPONSORS WHERE id_sponsors = ?");        $stmt->execute([$element]);        $currentFiles = $stmt->fetch();                $destination = $currentFiles['logo_sponsors']; // Initialize with the current sponsor logo        if ($_FILES['f_logo_img']['size'] > 0) {            // Delete existing sponsor logo file            if (!empty($currentFiles['logo_sponsors'])) {                $fileToDelete = $_SERVER['DOCUMENT_ROOT'] . $currentFiles['logo_sponsors'];                if (file_exists($fileToDelete)) {                    unlink($fileToDelete);                }            }            $destination = handleFileUpload($_FILES['f_logo_img'], $dossier, $extensions_valides, '91', '1025');        }                // Update the sponsor information in the database.        $updateResult = updateSponsorInfo($element, $zt_nom, $zt_site, $club, $summer, $winter, $destination);                if ($updateResult) {            retour_erreur(91, 3); // Successful update.        } else {            retour_erreur(91, 4); // Handle database update errors.        }                    } else {        retour_erreur(91, 7); // Handle form submission errors.    }            // Function to update sponsor information in the database.    function updateSponsorInfo($element, $zt_nom, $zt_site, $club, $summer, $winter, $destination) {        global $db;        $stmt = $db->prepare('UPDATE SPONSORS SET name_sponsors = ?, url = ?, is_club = ?, is_tournament_summer = ?, is_tournament_winter = ?, logo_sponsors = ? WHERE id_sponsors = ?');        return $stmt->execute([$zt_nom, $zt_site, $club, $summer, $winter, $destination, $element]);    }?>