<?php	include("../_includes/session_test.inc");	include("../_includes/_revolutionfc.inc");?><?php        $stmt = $db->prepare('select * from TEXT_pages where id_page = ? ');    $stmt->execute(['1']);        while ($curseur1 = $stmt->fetch()) {        extract($curseur1);        $texte = nl2br(stripslashes($page_text));        $texte = str_replace("<br /><br />", "", $texte);        $texte = str_replace("<br />", "", $texte);    }    Z?><!doctype html><html><head><meta charset="UTF-8"><title>RFC – Missions et Valeurs</title><?php	include("../_includes/head.inc");    echo "<body>";	include("../_includes/header.inc");?><!-- START OF THE CONTACT SECTION --><section>        <article class='wrapper heading'>        <h1 class='main-heading'>Missions et Valeurs du Révolution FC</h1>    </article>    	<article class="wrapper-text text-content">                <?php echo $texte ?>	    </article></section><!-- END OF THE CONTACT SECTION --><?php include("../_includes/footer.inc") ?>