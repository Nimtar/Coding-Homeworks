package VSU;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FilenameFilter;
import java.util.LinkedList;
import java.util.List;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        //TODO: Replace magic constant with args[0]
        String directoryName = "D:\\\u0422\u0415\u041a\u0421\u0422\u042b\\";
        File path = new File(directoryName);

        List<FileInputStream> inputStreamList = new LinkedList<>();

        /*
        The following code fills the list of FileInputStream
        with objects associated with files which are required in the task.
        */
        for (String fileName : path.list(new FilenameFilter() {
            //TODO: Replace current regex with "^in_\\d+.dat$"
            Pattern pattern = Pattern.compile("^\\d+\\..+$");
            @Override
            public boolean accept(File dir, String name) {
                return pattern.matcher(name).find();
            }
        })){
            inputStreamList.add(new FileInputStream(directoryName + fileName));
        }

        for (FileInputStream fin : inputStreamList){
            //see Runnable.java
            new Thread(() -> {
                System.out.println(fin.getChannel());
            }).start();
        }
    }
}
