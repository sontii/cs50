SELECT city, full_name
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20;
