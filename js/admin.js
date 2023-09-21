

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

    // Call the function to enable the toggle behavior
    toggleContentAdd();