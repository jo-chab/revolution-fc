<?php	include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");		unset($_GET);    $member = $_POST['element'];    $stmt2 = $db->prepare('DELETE from MEMBERS_STAFF WHERE id_member = ? ');    $execute = $stmt2->execute([        $member    ]);    if ($execute) {        $stmt2->closeCursor();        retour_erreur(25, 1);    } else {        retour_erreur(25, 2);    }?>