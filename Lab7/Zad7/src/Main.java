import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String []args) throws Exception {
//        myImplementation();
        Implementation();
    }
    public static void Implementation() throws Exception {
        CatalogTree tree = new CatalogTree(4);

        tree.add("A","","");
        tree.add("B","A","");
        tree.add("C","A","");
        tree.add("D","A","");
        tree.add("f1","A","");
        tree.add("D","B","A");
        tree.add("f1","B","A");
        tree.add("E","C","A");

        tree.display();

        CatalogTree tree2 = new CatalogTree(4);

        tree2.add("X","","");
        tree2.add("Y","X","");
        tree2.add("Z","X","");
        tree2.add("f1","X","");
        tree2.add("X","Y","X");
        tree2.add("f1","Y","X");
        tree2.add("Z","Z","X");
        tree2.add("f1","Z","X");

        tree2.display();
    }

    public static void myImplementation(){
        CatalogTreeElement str = new CatalogTreeElement("A");

        str.addCatalog("B");
        str.addCatalog("C");
        str.addCatalog("D");
        str.addCatalog("F1");

        str.getChilds().get(0).addCatalog("D");
        str.getChilds().get(0).addCatalog("f1");
        str.getChilds().get(1).addCatalog("e");

        System.out.println("-----------TREE-----------");
        System.out.println(str.toString());
        System.out.println("--------------------------");

        CatalogTreeElement tree2 = new CatalogTreeElement("X");
        tree2.addCatalog("Y");
        tree2.addCatalog("Z");
        tree2.addCatalog("f1");

        tree2.getChilds().get(0).addCatalog("X");
        tree2.getChilds().get(0).addCatalog("f1");

        tree2.getChilds().get(1).addCatalog("Z");
        tree2.getChilds().get(1).addCatalog("f1");

        System.out.println("-----------TREE-----------");
        System.out.println(tree2.toString());
        System.out.println("--------------------------");


    }
}
class CatalogTree {
    String[][][] tree;
    int size;
    public CatalogTree(int treeSize) {
        this.tree = new String[treeSize][treeSize+1][treeSize+1];
        this.size = treeSize;
    }

    public CatalogTree(String[][][] tree) {
        this.tree = tree;
    }

    public void add(String name,String parentName, String grandParentName) throws Exception {
//        System.out.println("dodawanie : "+grandParentName+" / "+parentName+" / "+name);
//        System.out.println("size: "+size);
        if(grandParentName.length()!=0)
        {
            //grandparent exist

            //searching grandparent
            int grandParentPos=-1;
            for(int i=0;i<size;i++)
            {
                String elem=tree[i][0][0];
                if(elem == grandParentName)
                {
                    grandParentPos=i;
                    break;
                }
            }
            if(grandParentPos<0)
                throw new Exception("There isn't a grandparent with this name.");

            if(parentName.length()!=0)
            {
                //grandparent exist
                //parent exist

                //searching parent
                int parentPos=-1;
                for(int i=1;i<size+1;i++)
                {
                    String elem = tree[grandParentPos][i][0];
                    if(elem==parentName)
                    {
                        parentPos=i;
                        break;
                    }
                }
                if(parentPos<0)
                    throw new Exception("There isn't a parent with this name.");

                //searching free space
                int free=-1;
                for(int i=0;i<size;i++)
                {
                    String elem = tree[grandParentPos][parentPos][i];
                    if(elem==null || elem.length()==0)
                    {
                        free=i;
                        break;
                    }
                }
                if(free<0)
                {
                    throw new Exception("There isn't enough space in parent.");
                }

                //adding

                tree[grandParentPos][parentPos][free]=name;
                return;
            }
            else {
                //grandparent exist
                //parent does not exist
                throw new Exception("Something went wrong. If there is a grandparent, parent must exist.");
            }

        }else
        {
            //grandparent does not exist

            if(parentName.length()!=0)
            {
                //grandparent does not exist
                //parent exist

                int parentPos=-1;
                for(int i=0;i<size;i++)
                {
                    String elem = tree[i][0][0];
                    if(elem==parentName)
                    {
                        parentPos=i;
                        break;
                    }
                }
                if(parentPos<0)
                    throw new Exception("There isn't a parent with this name.");

                //searching free space
                int free=-1;
                for(int i=1;i<size+1;i++)
                {
//                    System.out.println("---p--- "+parentPos+" - "+i);
//                    System.out.println("[0][0] = "+tree[0][0][0]);
//                    System.out.println("elem = "+tree[parentPos][i][0]);
                    String elem = tree[parentPos][i][0];
                    if(elem==null || elem.length()==0)
                    {
//                        System.out.println("znaleziono: "+parentPos+" - "+i);
                        free=i;
                        break;
                    }
                }
                if(free<0)
                {
                    throw new Exception("There isn't enough space in parent.");
                }
                tree[parentPos][free][0]=name;
                return;
            }
            else {
                //grandparent does not exist
                //parent does not exist

                //searching free space
                int free=-1;
                for(int i=1;i<size+1;i++)
                {
                    String elem = tree[i][0][0];
                    if(elem==null || elem.length()==0)
                    {
                        free=i;
                        break;
                    }
                }
                if(free<0)
                {
                    throw new Exception("There isn't enough space.");
                }
                tree[free][0][0]=name;
                return;
            }
        }
    }

    public void display(){
        int grandparent=0;
        int parent=0;
        int index=0;

        StringBuilder view=new StringBuilder();

        view.append("-----------TREE-----------\n");

        for(int i=0;i<size;i++)
        {
            String elem=tree[i][0][0];
            if(elem!=null)
            {
                view.append("|"+elem+"\n");

                for(int j=1;j<size+1;j++)
                {
                    String elem2=tree[i][j][0];
                    if(elem2!=null)
                    {
                        view.append("    |"+elem2+"\n");
                        for(int k=1;k<size+1;k++)
                        {
                            String elem3=tree[i][j][k];
                            if(elem3!=null)
                            {
                                view.append("        |"+elem3+"\n");
                            }
                        }
                    }
                }
            }
        }
        view.append("--------------------------\n");

        System.out.println(view.toString());
    }
}
class CatalogTreeElement{
    CatalogTreeElement parent;
    String name;
    List<CatalogTreeElement> childs;

    public CatalogTreeElement(String name) {
        parent = null;
        this.name = name;
        childs = new ArrayList<>();
    }

    public CatalogTreeElement getParent() {
        return parent;
    }

    public void setParent(CatalogTreeElement parent) {
        this.parent = parent;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<CatalogTreeElement> getChilds() {
        return childs;
    }

    public void setChilds(List<CatalogTreeElement> childs) {
        this.childs = childs;
    }

    public void addCatalog(String name){
        CatalogTreeElement newCatalog = new CatalogTreeElement(name);
        newCatalog.setParent(this);
        this.childs.add(newCatalog);
    }

    @Override
    public String toString() {
        //indents
        int countParents=0;
        CatalogTreeElement copiedRef = this;

        while (copiedRef.parent != null)
        {
            countParents++;
            copiedRef=copiedRef.parent;
        }

        StringBuilder builder = new StringBuilder();


        for(int i=0;i<countParents;i++)
        {
            builder.append("    ");
        }
        builder.append("| ");
        builder.append(name);
        builder.append("\n");


        for(int i=0;i<childs.size();i++)
        {
            for (int j=0;j<countParents+1;j++)
                builder.append("    ");
            builder.append(childs.get(i).toString());
        }

        return builder.toString();
    }
}