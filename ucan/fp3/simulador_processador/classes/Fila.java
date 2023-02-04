package classes;
public class Fila {
    public static int MAX = 15;
    private DescritorProcesso obj[] = new DescritorProcesso[MAX];
    private int entrada, saida, nroElementos;

    public Fila()
    {
        this.entrada = 0;
        this.saida = 0;
        this.nroElementos = 0;
    }
    public void incluir(DescritorProcesso o)
    {
        if(this.nroElementos == MAX)
        {
            System.out.println("Fila se encontra cheia");
            System.exit(1);
        }
        if((this.entrada+1) == MAX) this.entrada = 0;
        else
        {
            this.obj[this.entrada] = o;
            this.entrada++;
            this.nroElementos++;
        } 
    }
    public DescritorProcesso excluirNaEntrada()
    {
        DescritorProcesso valor;
        if(this.nroElementos == 0)
        {
            System.out.println("Fila esta vazia:)");
            System.exit(1);
        }
        valor = this.obj[this.entrada];
        if( (this.entrada == 0) && (this.nroElementos > 1) )
            this.entrada = MAX - 1;
        else
            if(this.nroElementos > 1) 
                this.entrada = entrada - 1;
        nroElementos--;
        return valor;
    }
    public DescritorProcesso excluir()
    {
        DescritorProcesso valor;
        if(this.nroElementos == 0)
        {
            System.out.println("A Fila esta vazia:");
            System.exit(1);
        }
        valor = this.obj[this.saida];
        this.obj[this.saida] = null;
        if((this.saida+1) == MAX) this.saida = 0;
        else
            if( this.nroElementos > 1) this.saida++;
        this.nroElementos--;
        return valor;
    }
    public void incluirNaSaida(DescritorProcesso v)
    {
        if( this.nroElementos == MAX)
        {
            System.out.println("A fila esta cheia");
            System.exit(1);
        }
        if((this.saida == 0) && (this.nroElementos > 0))
            this.saida = MAX-1;
        else
            if(this.nroElementos > 0)
                this.saida--;
        this.obj[this.saida] = v;
        this.nroElementos++;
    }
    public void print()
    {
        for(int c = this.saida; c!=this.entrada; c++)
        {
            if(c==MAX)
                c=0;
            System.out.println(this.obj[c]);
        }
    }

}
