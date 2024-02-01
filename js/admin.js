

    $(document).ready(function () {
        $('.menu-toggle-admin').click(function(){
            $('.sidebar').toggleClass('open');
        });
    });

    //Fonction qui ajoute l'icone quand il y a un sous-menu
    $('.admin-nav').each(function() {
        if ($(this).children('.sub-nav').length > 0) {
            $(this).children('.menu-element').addClass('has-sub');
        }
    });


    //Fonction qui ajoute la classe SELECTED quand on clique et qui active ou desactive le sous-menu
    $('.menu-element').click(function(event) {
        if ($(this).hasClass('selected')) {
            $(this).removeClass('selected');
            $(this).siblings('.sub-nav').slideUp(400);
        } else {
            $('.menu-element').removeClass('selected');
            $(this).addClass('selected');
            $('.sub-nav').not($(this).siblings('.sub-nav')).slideUp(400);
            $(this).siblings('.sub-nav').slideDown(400).css('display', 'flex');
        }
    });


    function toggleContentAdd() {
        const addButton = document.querySelector('.js-content-add');
        const contentAdd = document.querySelector('.content-add');

        addButton.addEventListener('click', () => {
            contentAdd.classList.toggle('is-active');
            addButton.classList.toggle('is-hide');
        });
    }
    function toggleContentUpdate() {
        const updateButtons = document.querySelectorAll('.js-content-update');

        updateButtons.forEach(updateButton => {
            updateButton.addEventListener('click', () => {
                const categoryId = updateButton.getAttribute('data-category');
                const contentUpdate = document.querySelector(`.content-update-${categoryId}`);

                contentUpdate.classList.toggle('is-active');
                updateButton.classList.toggle('is-not-active');
            });
        });
    }

    // Call the function to enable the toggle behavior
    toggleContentAdd();
    toggleContentUpdate();

    // Handle the "Cancel" button click event
    $('.js-cancel-update').click(function () {
        const contentUpdate = $(this).closest('.content-update');
        const categoryId = contentUpdate.attr('class').match(/content-update-(\d+)/)[1]; // Extract categoryId
        const updateButton = document.querySelector(`.js-content-update[data-category="${categoryId}"]`);

        contentUpdate.removeClass('is-active');
        updateButton.classList.remove('is-not-active');
    });




    document.addEventListener('DOMContentLoaded', function() {
        // Retrieve the last selected menu item from localStorage
        var lastSelectedItem = localStorage.getItem('selectedMenuItem');

        // If there was a last selected item, mark it as active
        if (lastSelectedItem) {
            var menuItem = document.querySelector(`.sidebar-menu a[href*="${lastSelectedItem}"]`);
            if (menuItem) {
                menuItem.classList.add('active');
                // If the selected menu item has a parent with sub-menu, open it
                var parentNav = menuItem.closest('.admin-nav');
                if (parentNav) {
                    parentNav.classList.add('open');
                }
            }
        }

        // Event listener for clicks on menu items
        document.querySelectorAll('.sidebar-menu a').forEach(item => {
            item.addEventListener('click', function(event) {
                // Remove the "active" class from all menu items
                document.querySelectorAll('.sidebar-menu a').forEach(item => {
                    item.classList.remove('active');
                });

                // Add the "active" class to the clicked menu item
                this.classList.add('active');

                // Store the selected menu item in localStorage
                localStorage.setItem('selectedMenuItem', this.getAttribute('href'));
            });
        });
    });

