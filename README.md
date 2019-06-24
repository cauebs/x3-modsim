- Para auxiliar no cálculo das integrais das distribuições, foi utilizada a Boost, uma coleção de bibliotecas.

- Para cálculo de quantil, a princípio foi utilizada uma aproximação numérica que aplica uma busca binária. Posteriormente descobrimos que essa função já está implementada na Boost, e então a utilizamos para o teste de significância da variância, na distribuição Qui-quadrado.

- Os headers contêm a documentação das funções.

- Para compilar e executar os testes, é fornecido o script `build_and_run_tests.sh`.
