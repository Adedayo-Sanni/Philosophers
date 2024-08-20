**1. Configuração Inicial**

Definir as Estruturas de Dados:
Estrutura para representar um filósofo, contendo atributos como ID, estado atual, tempos de comer, dormir e morrer, e um mutex para sincronizar ações.
Estrutura para os garfos (forks), que devem ser protegidos por mutexes.
Estrutura para os parâmetros da simulação (número de filósofos, tempos, etc.).

**2. Implementação da Lógica Básica**
Iniciar os Filósofos e Garfos:

Crie uma função para inicializar os filósofos e garfos. Os garfos devem ser representados como mutexes.
Crie uma função para iniciar a simulação e criar threads para cada filósofo.

Funções de Ação dos Filósofos:
Implemente as funções para as ações dos filósofos: comer, dormir, pensar, e pegar_garfo.
Cada ação deve ser sincronizada adequadamente usando mutexes para evitar condições de corrida.
Utilize gettimeofday para medir o tempo em milissegundos.

**3. Sincronização e Mensagens**

Sincronização das Ações:
Implemente mutexes para garantir que as mensagens de estado dos filósofos não sejam misturadas.
Assegure que o acesso aos garfos seja bem sincronizado, evitando deadlocks e condições de corrida.
Impressão das Mensagens:

Implemente a função para imprimir mensagens no formato necessário. Garanta que as mensagens sobre morte sejam exibidas rapidamente.

**4. Gerenciamento de Morte e Término da Simulação**

Detecção de Morte:
Crie uma função que verifica periodicamente se um filósofo morreu (baseado no time_to_die).
Termine a simulação se um filósofo morrer, imprimindo a mensagem apropriada.
Critério de Parada da Simulação:

Implemente a verificação para o argumento opcional number_of_times_each_philosopher_must_eat.
Finalize a simulação quando todos os filósofos tiverem comido o número de vezes necessário.

**5. Testes e Validações**

Testar Casos Básicos:
Teste o programa com diferentes números de filósofos e tempos, incluindo o caso especial de um único filósofo.
Verifique se os mutexes estão funcionando corretamente, sem deadlocks ou condições de corrida.

Testar Casos Limites:
Teste casos com tempos muito curtos ou muitos filósofos para garantir a robustez do programa.