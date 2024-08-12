import java.util.ArrayList;
import java.util.Scanner;

public class EjerciciosJava {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("Elige una opción:");
            System.out.println("1. Imprimir números del 1 al 100 e informar si el número es par");
            System.out.println("2. Imprimir números del 50 al 100 e informar si el número es primo, sino mostrar sus divisores");
            System.out.println("3. Pedir números por pantalla hasta que alguno sea mayor a 100 y además sea un número primo");
            System.out.println("4. Realizar una calculadora con operaciones aritméticas simples (+, -, *, /)");
            System.out.println("5. Ejemplo del uso de for-each");
            System.out.println("0. Salir");

            System.out.print("Ingresa tu elección: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    imprimirNumerosConPares();
                    break;
                case 2:
                    imprimirPrimosODivisores();
                    break;
                case 3:
                    pedirNumeroMayorYPrimo();
                    break;
                case 4:
                    calculadoraSimple();
                    break;
                case 5:
                    ejemploForEach();
                    break;
                case 0:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción no válida. Intenta de nuevo.");
                    break;
            }

            System.out.println();
        } while (opcion != 0);
    }

    // Método para imprimir números del 1 al 100 e informar si el número es par 
    public static void imprimirNumerosConPares() {
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                System.out.println(i + " es par");
            } else {
                System.out.println(i);
            }
        }
    }

    // Método para imprimir números del 50 al 100 e informar si el número es primo, sino mostrar sus divisores
    public static void imprimirPrimosODivisores() {
        for (int i = 50; i <= 100; i++) {
            if (esPrimo(i)) {
                System.out.println(i + " es primo");
            } else {
                System.out.print(i + " no es primo, divisores: ");
                mostrarDivisores(i);
            }
        }
    }

    public static boolean esPrimo(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void mostrarDivisores(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    // Método para pedir números por pantalla hasta que alguno sea mayor a 100 y además sea un número primo
    public static void pedirNumeroMayorYPrimo() {
        Scanner scanner = new Scanner(System.in);
        int numero;

        do {
            System.out.print("Ingresa un número: ");
            numero = scanner.nextInt();
        } while (numero <= 100 || !esPrimo(numero));

        System.out.println("El número " + numero + " es mayor a 100 y es primo.");
    }

    // Método para realizar una calculadora con operaciones aritméticas simples (+, -, *, /)
    public static void calculadoraSimple() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingresa el primer número: ");
        double num1 = scanner.nextDouble();

        System.out.print("Ingresa el segundo número: ");
        double num2 = scanner.nextDouble();

        System.out.print("Ingresa la operación (+, -, *, /): ");
        char operacion = scanner.next().charAt(0);

        double resultado = 0;
        switch (operacion) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                } else {
                    System.out.println("Error: División por cero no permitida.");
                    return;
                }
                break;
            default:
                System.out.println("Operación no válida.");
                return;
        }

        System.out.println("El resultado es: " + resultado);
    }

    // Método de ejemplo del uso de for-each 
    public static void ejemploForEach() {
        ArrayList<String> frutas = new ArrayList<>();
        frutas.add("Manzana");
        frutas.add("Banana");
        frutas.add("Cereza");

        // Uso de for-each para recorrer la lista de frutas
        for (String fruta : frutas) {
            System.out.println(fruta);
        }
    }
}
