<?php    include("../_includes/session_test.inc");        if (isset($_SESSION['auth']) && ($_SESSION['type'] == 1 || $_SESSION['type'] == 2)) {        header('Location: https://www.revolutionfc.ca/?m=10');        exit();    } elseif (!isset($_SESSION['auth'])) {        header('Location: https://www.revolutionfc.ca/admin/login.php');        exit();    }        $page = $_GET['p'];        include("../_includes/_revolutionfc.inc");    include("../_includes/head_admin.inc");?><body class="admin"><?php    include("../_includes/alert_messages_admin.inc");?><main class="dashboard">        <aside class="sidebar">        <?php include("../_includes/menu_admin.inc"); ?>    </aside>        <article class="dashboard-container">                <?php            $stmt_config = "SELECT * FROM CONFIG_admin LIMIT 1";            $result_config = $db->query($stmt_config);                        if ($result_config->rowCount() > 0) {                $row = $result_config->fetch(PDO::FETCH_ASSOC);                extract($row);                                $service = $maintenance;                $content = nl2br(stripslashes($text));                $content = str_replace("<br />", "", $content);                                if($service == 1){                    echo"        <div class='message-box maintenance'>            <div class='icon i-alert'></div>            <div class='text-content'>                $content            </div>        </div>                    ";                }            }                ?>                <div id="content-area">            <?php                include("../_includes/pages_admin.inc");            ?>        </div>                                <?php            if (!empty($page)) {                if ($page > 0) {                    if ($supprElement == 1) {                        echo '<div class="footer-dashboard">                                            <form class="content-delete" action="' . $actionForm . '" method="post">                                                <input type="hidden" name="element" value="' . $element . '">                                                <div class="btn-tertiary btn-text btn-delete small icon mobile-icon-only"><span>' . htmlspecialchars($supprText) . '</span></div>                                            </form>                                            <a class="btn-primary cta-back" href="javascript:history.go(-1)">Retour</a>                                        </div>';                    } else {                        echo '<div class="footer-dashboard">                                            <a class="btn-primary cta-back" href="javascript:history.go(-1)">Retour</a>                                        </div>';                    }                }            }            else {}        ?>        </article></main><?php    include("../_includes/footer_admin.inc");?><script>    function confirmDelete() {        return confirm("Êtes-vous sûr de vouloir supprimer cet élément ? Cette action est irréversible !");    }    const inputs = document.querySelectorAll(".prefilled");    function handleClick(event) {        event.target.classList.remove("prefilled");    }    inputs.forEach((input) => {        input.addEventListener("click", handleClick);    });    $(document).ready(function() {        $('.btn-update, .btn-disable, .btn-activate, .btn-validate, .btn-confirm').click(function() {            $(this).closest('form').submit();        });        $('.btn-delete').click(function() {            if (confirmDelete()) {                $(this).closest('form').submit();            }        });        // Handle the click event for the "Revert" button        $('.btn-revert').click(function() {            // Reset the form to its initial state            $(this).closest('form')[0].reset();        });    });</script></body></html>