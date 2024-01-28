app.get('/evenements/:event_title', (req, res) => {
    const eventTitle = req.params.event_title;

    // Update the database query to retrieve the event details based on the event title
    // Example: Assuming the 'events' table has a column 'title', you would modify the SQL query to use the event title as a parameter
    const query = 'SELECT * FROM events WHERE title = ?';

    // Execute the database query to retrieve the event details based on the event title
    db.query(query, [eventTitle], (err, result) => {
        if (err) {
            // Handle the error (e.g., render an error page)
            res.status(500).send('Error retrieving event details');
        } else {
            if (result.length > 0) {
                const eventDetails = result[0]; // Assuming the query returns a single event record

                // Update the rendering logic to render the event detail page with the retrieved event details
                res.render('event-detail', { event: eventDetails }); // Example: Using a template engine to render the event detail page
            } else {
                // Handle the case where the event with the provided title is not found (e.g., render a 404 page)
                res.status(404).send('Event not found');
            }
        }
    });
});