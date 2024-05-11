-- File: remove_low_scores.sql

-- Connect to the database
USE hbtn_0c_0;

-- Remove records with score <= 5 from the second_table
DELETE FROM second_table WHERE score <= 5;

