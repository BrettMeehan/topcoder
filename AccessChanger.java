import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class AccessChanger{
    public static String[] convert(String[] program){
        for(int i = 0; i < program.length; i++){
            String line = program[i];
            String code = line.replaceFirst("//.*", "");
            String comment = "";
            Pattern pattern = Pattern.compile("//.*");
            Matcher matcher = pattern.matcher(line);
            if(matcher.find())
                comment = matcher.group();
            program[i] = code.replaceAll("->", ".") + comment;
        }
        return program;
    }
}
