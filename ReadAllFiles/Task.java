package VSU;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.concurrent.Callable;

/**
 * Created by Nimtar on 24.09.2015.
 */
public class Task<V> implements Callable {
    private File file;
    private Scanner scanner;

    public Task(File file){
        this.file = file;
    }
    @Override
    public Double call() {
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        double retValue = 0;
        if (scanner.hasNextLine()) {
            retValue = executeOperation(Short.valueOf(scanner.nextLine()));
        }

        return retValue;
    }

    private double executeOperation(short operation){
        double retValue;
        switch (operation) {
            case 1: retValue = sum();
                break;
            case 2: retValue = mul();
                break;
            case 3: retValue = sumOfSqr();
                break;
            default:
                retValue = 0;
                System.out.println("Wrong operation in " + file.getName());
                break;
        }

        return retValue;
    }

    private double sum(){
        double v = 0;
        while (scanner.hasNextDouble()) {
            v += scanner.nextDouble();
        }
        return v;
    }

    private double mul(){
        double v = 1;
        while (scanner.hasNextDouble()) {
            v *= scanner.nextDouble();
        }
        return v;
    }

    private double sumOfSqr(){
        double v = 0;
        while (scanner.hasNextDouble()) {
            double temp = scanner.nextDouble();
            v += temp * temp;
        }
        return v;
    }
}
