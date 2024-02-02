

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

