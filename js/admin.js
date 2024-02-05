

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
        const addButton = $('.js-content-add');
        const contentAdd = $('.content-add');

        addButton.on('click', () => {
            contentAdd.slideToggle(400);
            addButton.toggleClass('is-hide');
        });
    }

    function toggleContentUpdate() {
        const updateButtons = $('.js-content-update');

        updateButtons.each((index, updateButton) => {
            $(updateButton).on('click', () => {
                const categoryId = $(updateButton).attr('data-category');
                const contentUpdate = $(`.content-update-${categoryId}`);

                contentUpdate.slideToggle(400);
                $(updateButton).toggleClass('is-not-active');
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




    function confirmDelete() {
        return confirm("Êtes-vous sûr de vouloir supprimer cet élément ? Cette action est irréversible !");
    }


    const inputs = document.querySelectorAll(".prefilled");
    function handleClick(event) {
        event.target.classList.remove("prefilled");
    }
    inputs.forEach((input) => {
        input.addEventListener("click", handleClick);
    });

    $(document).ready(function() {
        $('.btn-update, .btn-disable, .btn-activate, .btn-validate, .btn-confirm').click(function() {
            $(this).closest('form').submit();
        });

        $('.btn-delete').click(function() {
            if (confirmDelete()) {
                $(this).closest('form').submit();
            }
        });

        // Handle the click event for the "Revert" button
        $('.btn-revert').click(function() {
            // Reset the form to its initial state
            $(this).closest('form')[0].reset();
        });

    });

