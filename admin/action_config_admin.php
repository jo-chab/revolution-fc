<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        unset($_GET);        $websiteUrl = isset($_POST['zt_url']) ? nl2br(stripslashes($_POST['zt_url'])) : retour_erreur(2, 7);    $root = isset($_POST['zt_path']) ? nl2br(stripslashes($_POST['zt_path'])) : retour_erreur(2, 7);            $stmt = $db->prepare('UPDATE CONFIG_admin SET config_url = ?, config_path = ? WHERE id_config = 1');    $execute = $stmt->execute([        $websiteUrl,        $root    ]);        if ($execute) {        $stmt->closeCursor();        retour_erreur(2, 3);    } else {        retour_erreur(2, 4);    }?>