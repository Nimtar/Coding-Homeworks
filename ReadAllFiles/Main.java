package VSU;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) {

        //TODO: Replace magic constant with args[0]
        String directoryName = "D:\\\u0422\u0415\u041a\u0421\u0422\u042b\\";
        File path = new File(directoryName);

        //TODO: Replace current regex with "^in_\\d+.dat$"
        File[] files = path.listFiles((dir, name) -> {
            return Pattern.compile("^\\d+\\..+$").matcher(name).find();
        });

        ExecutorService pool = Executors.newFixedThreadPool(files.length);
        LinkedList<Future<Double>> futureList = new LinkedList<>();

        for (File file : files) {
            futureList.add(pool.submit(new Task<Double>(file)));
        }

        double result = 0;
        for (Future<Double> future : futureList) {
            try {
                result += future.get();
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }
        FileWriter fileWriter;
        try {
            fileWriter = new FileWriter(directoryName + "out.dat", false);
            fileWriter.write(String.valueOf(result));
            fileWriter.flush();
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
