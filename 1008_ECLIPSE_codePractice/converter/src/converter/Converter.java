package converter;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IOUtils;
import org.apache.hadoop.io.SequenceFile;
import org.apache.hadoop.io.Writable;
import org.apache.hadoop.util.ReflectionUtils;


public class Converter {
    public static void main(String args[]) throws Exception {
        System.out.println("Readeing Sequence File");
        Configuration conf = new Configuration();
        conf.addResource(new Path("/home/manohar/prog/hadoop-2.6.0/etc/hadoop/core-site.xml"));
        conf.addResource(new Path("/home/manohar/prog/hadoop-2.6.0/etc/hadoop/hdfs-site.xml"));  
        FileSystem fs = FileSystem.get(conf);
        Path path = new Path("/home/manohar/USCF15/572-IR/Assignment1/nutch/runtime/local/crawl/segments/20150921232329/content/part-00000/data");
        SequenceFile.Reader reader = null;      
        try {
            reader = new SequenceFile.Reader(fs, path, conf);
            Writable key = (Writable) ReflectionUtils.newInstance(reader.getKeyClass(), conf);
            Writable value = (Writable) ReflectionUtils.newInstance(reader.getValueClass(), conf);
            while (reader.next(key, value)) {
                System.out.println(key + "  <===>  " + value.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            IOUtils.closeStream(reader);
        }
    }
}