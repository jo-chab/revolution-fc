<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");?>    <!doctype html>    <html><head>    <meta charset="UTF-8">    <title>Membres de la direction</title>        <?php        include("../_includes/head.inc");        echo "<body>";        include("../_includes/header.inc");    ?>            <!-- START OF THE CONTACT SECTION -->    <section>        <article>                        <h2 class="section-title">Personnel administratif</h2>            <ul class="list-people grid-layout col-3">                <?php                    $stmtList = $db->prepare('SELECT * from MEMBERS_ADMIN ORDER BY                    CASE                        WHEN member_function = "Directeur Général" THEN 1                        ELSE 2                    END, member_function ASC');                    $stmtList->execute();                                        $resultsList = $stmtList->fetchAll(PDO::FETCH_ASSOC);                    foreach ($resultsList as $result) {                        $function = nl2br(stripslashes($result['member_function']));                        $name = nl2br(stripslashes($result['member_name']));                                                // Check if member_img is not empty                        $img = nl2br(stripslashes($result['member_img']));                        $imgUrl = "../".$img;                        $imgContainer = !empty($img) ? "<div class='list-people-img' style='background-image: url($imgUrl)'></div>" : '';                                                // Check if member_legend is not empty                        $legend = nl2br(stripslashes($result['member_legend']));                        $legendContainer = !empty($legend) ? "<div class='list-people-legend'>$legend</div>" : '';                                                // Check if member_email is not empty                        $email = nl2br(stripslashes($result['member_email']));                        $emailContainer = !empty($email) ? "<a class='list-people-email' href='mailto:$email'>$email</a>" : '';                                                echo "            <li class='people-el'>                $imgContainer                <div class='list-people-function'>$function</div>                <div class='list-people-name'>$name</div>                $legendContainer                $emailContainer            </li>                ";                    }                                                ?>            </ul>                </article>    </section>    <!-- END OF THE CONTACT SECTION --><?php include("../_includes/footer.inc") ?>