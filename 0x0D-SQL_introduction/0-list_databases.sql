#!/bin/bash

# Prompt user for MySQL credentials
read -p "MySQL Username: " username
read -sp "MySQL Password: " password

# Execute MySQL query to list databases
mysql -u$username -p$password -e "SHOW DATABASES;"

