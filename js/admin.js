

    $(document).ready(function () {
        $('.menu-toggle-admin').click(function(){
            $('.sidebar').toggleClass('open');
        });
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