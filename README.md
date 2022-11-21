# TP2-algoritmos-ordenacao

### Executando o projeto

No diretório do projeto, executar:

##### Quicksort recursivo / nao recursivo / empilha inteligente
`./bin/run.out quicksort -v [variacao] -s [semente] -i ./arquivo_entrada.txt -o ./arquivo_saida`

##### Quicksort Mediana
`./bin/run.out quicksort -v [variacao] -k [K elementos] -s [semente] -i ./arquivo_entrada.txt -o ./arquivo_saida`

##### Quicksort Selecao
`./bin/run.out quicksort -v [variacao] -m [tamanho] -s [semente] -i ./arquivo_entrada.txt -o ./arquivo_saida`

No qual:

**[Obrigatorio]** `-v  "numero do algoritmo quicksort"`  
- 1 - Quicksort recursivo
- 2 - Quicksort mediana
- 3 - Quicksort selecao
- 4 - Quicksort nao recursivo
- 5 - Quicksort empilha inteligente  

**[Obrigatorio]** `-s  "numero da semente"` (semente utilizada para geracao de numeros aleatorios)  

**[Obrigatorio]** `-i  "nome do arquivo de entrada"`  (entrada em formato .txt)  
              
**[Obrigatorio]** `-o  "nome do arquivo de saída"`    (saída em formato .txt)

**[Obrigatorio p/ quicksort mediana]** `-k  "numero k"` (numero k de elementos)

**[Obrigatorio p/ quicksort selecao]** `-m  "numero m"` (tamanho m da particao)

#### Exemplo de uso:

`./bin/run.out quicksort -v 1 -s 10 -i ./samples/teste.txt -o ./arquivo_saida`
`./bin/run.out quicksort -v 2 -k 3 -s 10 -i ./samples/teste.txt -o ./arquivo_saida`
`./bin/run.out quicksort -v 3 -m 10 -s 10 -i ./samples/teste.txt -o ./arquivo_saida`
`./bin/run.out quicksort -v 4 -s 10 -i ./samples/teste.txt -o ./arquivo_saida`
