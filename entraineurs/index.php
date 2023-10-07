<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");        if(isset($_GET['category']))    {        $categoryUrl=$_GET['category'];    }    ?>            <!doctype html>    <html><head>    <meta charset="UTF-8">    <title>The coach corner</title>        <?php        include("../_includes/head.inc");        echo "<body>";        include("../_includes/header.inc");    ?>        <section>                <article class="wrapper-text">                        <?php if (isset($_SESSION['auth']) && ($_SESSION['type'] >= 2)): ?>                                <h1>The coach corner</h1>                <h4 style="text-align: center">Bienvenue dans votre zone technique. Cette zone vous est réservée et contient tous les documents qui seront mis en ligne par le staff technique du club</h4>                                <ul class="list-category grid-system grid-col-3">                    <?php                                                $stmt = $db->prepare('SELECT * from DOCS_technic_category order by id_category ASC');                        $stmt->execute();                                                $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                                                foreach ($results as $result) {                            $title = $result['category_name'];                            $selectedCategory = $result['id_category'];                            echo "                    <li class='category-element' data-category='$selectedCategory'>$title</li>                            ";                        }                    ?>                                    </ul>                <?php                                if(empty($_GET['category']))                {                                } else {                    echo "<ul class='list-subcategory grid-system grid-col-3'>";                    $selectedCategory = isset($categoryUrl) ? $categoryUrl : null;                                        if (empty($selectedCategory) || $selectedCategory == 0) {                        $stmtFilterCat = $db->prepare("SELECT * FROM DOCS_technic_subcategory");                    } else {                        $stmtFilterCat = $db->prepare("SELECT * FROM DOCS_technic_subcategory WHERE reference_category = ?");                    }                    $stmtFilterCat->execute([$selectedCategory]);                    $resultsCat = $stmtFilterCat->fetchAll(PDO::FETCH_ASSOC);                                        foreach ($resultsCat as $result) {                        $name = nl2br(stripslashes($result['subcategory_name']));                        $subcategory = $result['id_subcategory'];                        echo "<li><a class='subcategory-element' href='documents?subcategory=$subcategory'>$name</a></li>";                    }                    echo "</ul>";                }                                ?>                                        <?php else : ?>                                <div class='w-alert-message icon i-alert'>                    <p class='alert-message alert-error' style="text-align: center; gap: 2rem;">Access refusé : Vous n'avez pas les autorisations nécessaires pour accéder à cette page.<a class="btn-secondary ghost-white cta-back" href="../index.php">Retour au site</a></p>                </div>                        <?php endif ?>                        </article>        </section>        <script>        // Function to set the 'is-active' class based on the category parameter        function setActiveCategory() {            const currentUrl = window.location.href;            const match = currentUrl.match(/category=(\d+)/);            if (match) {                const categoryValue = match[1];                categoryElements.forEach(element => {                    const dataCategory = element.getAttribute('data-category');                    if (dataCategory === categoryValue) {                        element.classList.add('is-active');                    } else {                        element.classList.remove('is-active');                    }                });            }        }        // Add click event listener to category-element elements        const categoryElements = document.querySelectorAll('.category-element');        categoryElements.forEach(element => {            element.addEventListener('click', () => {                // Get the data-category attribute value                const selectedCategory = element.getAttribute('data-category');                // Get the current URL                const currentUrl = window.location.href;                // Check if the URL already contains a category parameter                if (currentUrl.includes('category=')) {                    // Update the existing category parameter                    const newUrl = currentUrl.replace(/category=\d+/, `category=${selectedCategory}`);                    window.location.href = newUrl;                } else {                    // Add the category parameter to the URL                    const separator = currentUrl.includes('?') ? '&' : '?';                    const newUrl = `${currentUrl}${separator}category=${selectedCategory}`;                    window.location.href = newUrl;                }                // Remove 'is-active' class from all category-elements                categoryElements.forEach(element => {                    element.classList.remove('is-active');                });                // Add 'is-active' class to the clicked element                element.classList.add('is-active');            });        });        // Call setActiveCategory to set 'is-active' class on page load        setActiveCategory();            </script><?php include("../_includes/footer.inc") ?>