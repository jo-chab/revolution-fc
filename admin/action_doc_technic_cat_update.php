<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        unset($_GET);        if (isset($_POST['zt_title'])) {        $categoryName = $_POST['zt_title'];    } else {        retour_erreur(37, 23);    }        $element = $_POST['element'];        $stmt = $db->prepare("UPDATE DOCS_technic_category SET category_name = ? WHERE id_category = ?");    $execute = $stmt->execute([        $categoryName,        $element    ]);        if ($execute) {        $stmt->closeCursor();        retour_erreur(37, 3);    } else {        retour_erreur(37, 4);    }?>