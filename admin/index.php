<?php    include("../_includes/session_test.inc");        if (isset($_SESSION['auth']) && ($_SESSION['type'] == 1 || $_SESSION['type'] == 2)) {        header('Location: https://www.revolutionfc.ca/?m=10');        exit();    } elseif (!isset($_SESSION['auth'])) {        header('Location: https://www.revolutionfc.ca/admin/login.php');        exit();    }        $page = $_GET['p'];        include("../_includes/_revolutionfc.inc");    include("../_includes/head_admin.inc");?><section class="dashboard">        <aside class="sidebar">                <ul class="sidebar-menu">            <?php include("../_includes/menu_admin.inc"); ?>        </ul>        </aside>        <article class="dashboard-container">                <?php            include("../_includes/alert_messages_admin.inc");            include("../_includes/pages_admin.inc");        ?>                <?php            if (!empty($page)) {                if ($page > 0) {                    if ($supprElement == 1) {                        echo '<div class="footer-dashboard">                                            <form class="content-delete" action="' . $actionForm . '" method="post">                                                <input type="hidden" name="element" value="' . $element . '">                                                <input type="submit" class="cta-delete" value="' . htmlspecialchars($supprText) . '" onclick="return confirmDelete();"/>                                            </form>                                            <a class="btn-primary cta-back" href="javascript:history.go(-1)">Retour</a>                                        </div>';                    } else {                        echo '<div class="footer-dashboard">                                            <a class="btn-primary cta-back" href="javascript:history.go(-1)">Retour</a>                                        </div>';                    }                }            } else {            }        ?>                <script>                        function confirmDelete() {                return confirm("Are you sure you want to delete this element?");            }                        const inputs = document.querySelectorAll(".prefilled");            function handleClick(event) {                event.target.classList.remove("prefilled");            }            inputs.forEach((input) => {                input.addEventListener("click", handleClick);            });            $(document).ready(function() {                $('.btn-update, .btn-disable, .btn-activate, .btn-validate').click(function() {                    $(this).closest('form').submit();                });                            $('.btn-delete').click(function() {                   if (confirmDelete()) {                        $(this).closest('form').submit();                    }                });                // Handle the click event for the "Revert" button                $('.btn-revert').click(function() {                    // Reset the form to its initial state                    $(this).closest('form')[0].reset();                });                            });                </script>        </article></section><?php    include("../_includes/footer_admin.inc");?>