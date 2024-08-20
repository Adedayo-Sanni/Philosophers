![Philo Header](https://github.com/Adedayo-Sanni/philo/blob/main/19.png)

# Philo

## Descrição

O projeto **Philo** é uma implementação do clássico problema dos filósofos, utilizando threads e mutexes para simular o comportamento de filósofos sentados ao redor de uma mesa, competindo por garfos para comer. O objetivo principal é evitar que os filósofos morram de fome, sincronizando o acesso aos garfos e garantindo que todos possam comer e sobreviver o máximo de tempo possível.

## Objetivo

O objetivo deste projeto é aprender e aplicar conceitos de programação concorrente, como threads, mutexes e sincronização de recursos compartilhados. O projeto também reforça a importância de evitar condições de corrida e deadlocks em ambientes de programação paralela.

## Regras do Projeto

- **Sem Variáveis Globais:** O uso de variáveis globais é estritamente proibido.
- **Parâmetros do Programa:** O programa deve receber os seguintes argumentos:
  - `number_of_philosophers`: Número de filósofos (e garfos) na mesa.
  - `time_to_die`: Tempo em milissegundos que um filósofo pode ficar sem comer antes de morrer.
  - `time_to_eat`: Tempo em milissegundos que um filósofo leva para comer.
  - `time_to_sleep`: Tempo em milissegundos que um filósofo dorme após comer.
  - `number_of_times_each_philosopher_must_eat` (opcional): Número mínimo de vezes que cada filósofo deve comer antes da simulação terminar. Se não for especificado, a simulação para quando um filósofo morre.
  
- **Formato das Mensagens de Log:** 
  - As mensagens devem seguir o formato `timestamp_in_ms X is doing_action`, onde `timestamp_in_ms` é o tempo atual em milissegundos e `X` é o número do filósofo.
  - As ações possíveis incluem: "has taken a fork", "is eating", "is sleeping", "is thinking", "died".

- **Sincronização:** 
  - As ações dos filósofos devem ser sincronizadas para evitar condições de corrida.
  - Cada garfo deve ser protegido por um mutex para evitar que dois filósofos peguem o mesmo garfo simultaneamente.
  
- **Terminação da Simulação:** A simulação termina quando um filósofo morre ou, opcionalmente, quando todos os filósofos tiverem comido um número específico de vezes.

## Compilação e Execução

### Requisitos
- GCC ou outro compilador C compatível.
- Biblioteca `pthread` para threads e sincronização.

### Compilação
1. Clone este repositório.
2. Navegue até o diretório `philo/`.
3. Execute o comando `make` para compilar o projeto.

### Execução
Após a compilação, o programa pode ser executado com os seguintes parâmetros:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
./philo 5 800 200 200
