-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
-- 3 witness

SELECT *
FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28;

-- RUTH:  Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away
-- EUGENE:  Earlier this morning ATM on Fifer Street and saw the thief there withdrawing some money

-- RAYMOND:  As the thief was leaving the courthouse talked to them for less than a minute earliest
-- flight out of Fiftyville tomorrow purchase the flight ticket.

SELECT name, activity, courthouse_security_logs.license_plate, minute
FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate = people.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute > 24 AND minute < 26;

--name | activity | license_plate | minute
--Patrick | exit | 5P2BI95 | 16
--Ernest | exit | 94KL13X | 18
--Amber | exit | 6P58WS2 | 18
--Danielle | exit | 4328GD8 | 19
--Roger | exit | G412CB7 | 20
--Elizabeth | exit | L93JTIZ | 21
--Russell | exit | 322W7JE | 23
--Evelyn | exit | 0NTHK55 | 23

SELECT *
FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";

-- 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35

SELECT *
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";

-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 49610011 | 686048 | 2010 | 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE | 26013199 | 514354 | 2012 | 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35
-- 458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3 | 16153065 | 458378 | 2012 | 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN | 28296815 | 395717 | 2014 | 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ | 25506511 | 396669 | 2014 | 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 | 28500762 | 467400 | 2014 | 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 | 76054385 | 449774 | 2015 | 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0 | 81061156 | 438727 | 2018 | 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30

SELECT caller, receiver
FROM phone_calls JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60 AND caller = people.name;

--221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
--224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
--233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
--251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
--254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
--255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
--261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
--279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
--281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

SELECT *
FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;

-- caller and the atm user is the thief
--id | name | phone_number | passport_number | license_plate | id | caller | receiver | year | month | day | duration
--398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7 | 221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
--560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55 | 224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
--560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55 | 251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 | 254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE | 255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
--907148 | Kimberly | (031) 555-6622 | 9628244268 | Q12B3Z3 | 261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
--395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN | 279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
--438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0 | 281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

SELECT *
FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;

-- receiver is ACCOMPLICE
--id | name | phone_number | passport_number | license_plate | id | caller | receiver | year | month | day | duration
--567218 | Jack | (996) 555-8899 | 9029462229 | 52R0Y8U | 221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
--251693 | Larry | (892) 555-8872 | 2312901747 | O268ZZ0 | 224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0 | 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
--626361 | Melissa | (717) 555-1342 | 7834357192 |  | 251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
--250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6 | 254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
--847116 | Philip | (725) 555-3243 | 3391710505 | GW362R6 | 255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
--712712 | Jacqueline | (910) 555-3251 |  | 43V0R5D | 261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
--953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04 | 279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
--484375 | Anna | (704) 555-2131 |  |  | 281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

SELECT name, caller
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Fifer Street"
AND atm_transactions.transaction_type = "withdraw" AND duration < 60;

-- mornig atm withdraw on fifer street and calling less than a min
-- name | caller
-- Ernest | (367) 555-5533
-- Ernest | (367) 555-5533
-- Russell | (770) 555-1861
-- Bobby | (826) 555-1652
-- Madison | (286) 555-6063
-- Victoria | (338) 555-6650

SELECT MIN(hour)
FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = 2020 AND month = 7 AND day = 29 AND abbreviation = "CSF";
-- 8

SELECT hour, minute
FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND abbreviation = "CSF";
-- 8

SELECT name, people.passport_number
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON airports.id = flights.origin_airport_id
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Fifer Street"
AND atm_transactions.transaction_type = "withdraw" AND duration < 60 AND hour = 8 AND minute = 20 AND abbreviation = "CSF";

--Ernest | 5773159633
--Ernest | 5773159633
--Bobby | 9878712108
--Madison | 1988161715

--name | activity | license_plate | minute
--Ernest | exit | 94KL13X | 18
-- AND berthold call id 233

SELECT city, full_name
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20;