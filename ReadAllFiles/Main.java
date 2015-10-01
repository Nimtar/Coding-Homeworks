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

        String directoryName = args[0];
        //TODO: Replace current regex with "^in_\\d+.dat$"
        String pattern = "^\\d+\\..+$";

        double result = executeExprInFiles(findFiles(directoryName, pattern));
        writeOutFile(result, directoryName + "out.dat");
    }

    private static void writeOutFile(double result, String outFileName) {
        FileWriter fileWriter;
        try {
            fileWriter = new FileWriter(outFileName, false);
            fileWriter.write(String.valueOf(result));
            fileWriter.flush();
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static File[] findFiles(String directoryName, String pattern){
        return new File(directoryName).listFiles((dir, name) -> {
            return Pattern.compile(pattern).matcher(name).find();
        });
    }
    
    private static double executeExprInFiles(File[] files){
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
        return result;
    }
}
