<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        unset($_GET);    $id_job = $_POST['element'];        $stmt = $db->prepare('DELETE from EMPLOIS WHERE id_job = ? ');    if ($stmt->execute([$id_job])) {        $stmt->closeCursor();        retour_erreur(24, 924);    } else {        retour_erreur(24, 925);    }?>