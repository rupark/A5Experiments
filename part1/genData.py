#!/usr/bin/env python3
import csv

with open('data.txt', mode='w') as employee_file:
        employee_writer = csv.writer(employee_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        for x in range(2000000):
                employee_writer.writerow(['John', 'Smith', 'Accounting', 'November', 5, 300, 'Graduate', 1.5, 2.5, 49])
        for x in range(2000000):
                employee_writer.writerow(['Erica', 'Meyers', 'IT', 'March', 3, 400, 'Non-Graduate', 5.0, 5.0, 22])
        for x in range(2000000):
                employee_writer.writerow(['Lisa', 'Jones', 'Marketing', 'June', 10, 50, 'Graduate', 3.0, 4.9, 51])
