/*
 * Дан текстовый файл с неизвестным числом строк в формате
 * "Фамилия Имя курс оценка1 оценка2 оценка3 оценка4 оценка5"
 * Нужно, используя свой класс, вывести на консоль фамилии и 
 * средние арифметические оценок студентов в порядке, обратном тому, что был
 * в файле.
*/

using System;
using System.Collections.Generic;
using System.IO;

namespace AboutStudents {
    internal class Program {
        private static void Main (string [] args) {
            Stack<Record> stack = new Stack<Record>();

            StreamReader reader = new StreamReader("1.txt");

            while (!reader.EndOfStream) {
                stack.Push(Record.parse(reader.ReadLine()));
            }

            while (stack.Count != 0) {
                var record = stack.Pop();
                Console.WriteLine(record.surname + ' ' + record.getAvgMark());
            }
            Console.ReadKey();
        }
    }


    internal class Record {
        public Record () {
            marks = new short[5];
        }

        public static Record (string name, string surname, short year, short [] marks) {
            this.name = name;
            this.surname = surname;
            this.year = year;
            this.marks = marks;
        }

        public string name { get; set; }

        public string surname { get; set; }

        public short year { get; set; }

        public short [] marks { get; set; }

        private float calcAvgMark () {
            float avgMark = 0;
            foreach (var mark in marks) {
                avgMark += mark;
            }
            return avgMark /= marks.Length;
        }

        public float getAvgMark () {
            return calcAvgMark();
        }

        public Record parse (string str) {
            string [] splitStrings = str.Split(new [] {' '});

            short i = 0;

            string surname = splitStrings[i++];
            string name = splitStrings[i++];
            short year = short.Parse(splitStrings[i++]);
            var marks = new short[5];
            for (int j = 0; j < marks.Length; j++) {
                marks[j] = short.Parse(splitStrings[i++]);
            }

            return new Record(name, surname, year, marks);
        }
    }
}
