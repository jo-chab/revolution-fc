
    // Fonction pour selectionner le type de filtre
    const filterButtonsSelect = document.querySelectorAll('.filter-select .btn-filter');
    const filterContent = document.querySelectorAll('[class^="filter-buttons-"]');

    filterButtonsSelect.forEach(buttonSelect => {
        buttonSelect.addEventListener('click', () => {
            // Extract the last part of the button's id
            const filterSelect = buttonSelect.getAttribute("id").replace("btn-filter-", "");

            // Remove the "is-inactive" class from all buttons
             filterButtonsSelect.forEach(btn => {
                 btn.classList.add('is-inactive');
             });
            // Toggle the "is-inactive" class on the clicked button
            buttonSelect.classList.toggle('is-inactive');

            // Find the corresponding filter-buttons element
            const filterButtonsElement = document.querySelector(`.filter-buttons-${filterSelect}`);

            // Hide all filter-buttons elements
            filterContent.forEach(element => {
                element.classList.add('is-hidden');
            });

            // Toggle the "is-hidden" class on the filter-buttons element
            filterButtonsElement.classList.toggle('is-hidden');

        });
    });


    //const filterButtons = document.querySelectorAll(".btn-filter");
    const filterButtonsSeason = document.querySelectorAll(".filter-buttons-season .btn-filter");
    const filterButtonsCity = document.querySelectorAll(".filter-buttons-city .btn-filter");
    const filterButtonsType = document.querySelectorAll(".filter-buttons-type .btn-filter");
    const fieldEls = document.querySelectorAll(".field-el");

    filterButtonsSeason.forEach(buttonSeason => {
        buttonSeason.addEventListener("click", function() {
            const filterSeason = buttonSeason.getAttribute("id").replace("cta-field-", "");

            fieldEls.forEach(fieldEl => {
                const season = fieldEl.getAttribute("data-season");

                if (filterSeason === "all" || season === filterSeason) {
                  fieldEl.classList.remove("is-hide");
                } else {
                  fieldEl.classList.add("is-hide");
                }
            });
            filterButtonsSeason.forEach(btn => {
            if (btn === buttonSeason) {
                btn.classList.remove("is-inactive");
            }
            else {
                btn.classList.add("is-inactive");
            }
          });
        });
    });

    filterButtonsCity.forEach(buttonCity => {
        buttonCity.addEventListener("click", function() {
            const filterCity = buttonCity.getAttribute("id").replace("cta-city-", "");

            fieldEls.forEach(fieldEl => {
                const city = fieldEl.getAttribute("data-city");

                if (filterCity === "all" || city === filterCity) {
                  fieldEl.classList.remove("is-hide");
                } else {
                  fieldEl.classList.add("is-hide");
                }
            });

    //        filterButtonsCity.forEach(btnCity => {
    //        if (btnCity === buttonCity) {
    //            btnCity.classList.remove("is-inactive");
    //        }
    //        else {
    //            btnCity.classList.add("is-inactive");
    //        });

        });
    });

    filterButtonsType.forEach(button => {
        button.addEventListener("click", function() {
            const filterType = button.getAttribute("id").replace("cta-type-", "");

            fieldEls.forEach(fieldEl => {
                const type = fieldEl.getAttribute("data-terrain");

                if (filterType === "all" || type === filterType) {
                  fieldEl.classList.remove("is-hide");
                } else {
                  fieldEl.classList.add("is-hide");
                }
            });
        });
    });