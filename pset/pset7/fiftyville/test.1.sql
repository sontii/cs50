SELECT name, people.passport_number
FROM people
;





SELECT name, people.passport_number
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON airports.id = flights.origin_airport_id
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Fifer Street"
AND atm_transactions.transaction_type = "withdraw" AND duration < 60 AND flights.hour = 8 AND flights.minute = 20 AND abbreviation = "CSF"
AND courthouse_security_logs.year = 2020 AND courthouse_security_logs.month = 7 AND courthouse_security_logs.day = 28 
AND courthouse_security_logs.hour = 10 AND courthouse_security_logs.minute > 24 AND courthouse_security_logs.minute < 26;