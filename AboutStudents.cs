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
                stack.Push(new Record().parse(reader.ReadLine()));
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

        public Record (string name, string surname, short year, short [] marks) {
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

        // I don't know how to do it in right way
        public Record parse (string str) {
            int indOfSpace = str.IndexOf(' ');
            surname = str.Substring(0, indOfSpace);
            str = str.Remove(0, indOfSpace + 1);

            indOfSpace = str.IndexOf(' ');
            name = str.Substring(0, indOfSpace);
            str = str.Remove(0, indOfSpace + 1);

            year = short.Parse(str.Substring(0, str.IndexOf(' ')));
            str = str.Remove(0, str.IndexOf(' ') + 1);

            for (int i = 0; i < marks.Length; i++) {
                indOfSpace = str.IndexOf(' ');
                if (-1 == indOfSpace) {
                    indOfSpace = str.Length;
                }
                marks[i] = short.Parse(str.Substring(0, indOfSpace));
                str = str.Remove(0, str.IndexOf(' ') + 1);
            }

            return this;
        }
    }
}
