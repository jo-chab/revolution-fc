<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");    include("../_includes/_fileUpload.inc"); // Include the file with the handleFileUpload function        unset($_GET);        if (isset($_POST['zt_title'])) {        $zt_title = nl2br(stripslashes($_POST['zt_title']));    } else {        retour_erreur(36, 23);    }    if (isset($_POST['subcategory_select'])) {        $subcategory = $_POST['subcategory_select'];    } else {        retour_erreur(36, 23);    }        $database = $_POST['db-name'];        $page = '36';    // Handle file upload    $dossier = "docs/_technique/";    $destination = handleDocUpload($_FILES['f_document'], $dossier, $page);        $stmt = $db->prepare("INSERT Into $database (doc_title, doc_link, doc_subcategory) Values (?, ?, ?)");        if ($stmt->execute([        addslashes($zt_title),        $destination,        $subcategory    ])) {        $stmt->closeCursor();        retour_erreur(36, 401);    } else {        retour_erreur(36, 402);    }?>