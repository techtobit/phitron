from django import forms
from django.core import validators
from forms.models import Student


class contactForm(forms.Form):
    name = forms.CharField( label='Full Name: ', help_text='Total lenght must be within 60 Char',required=False, error_messages={'required': 'Please Enter Name'}, widget=forms.TextInput(attrs={'id': 'text_area', 'class': 'class1 class2', 'placeholder': 'Enter Your Name' },) )
    email = forms.EmailField(label='User Email')
    age = forms.IntegerField(widget=forms.NumberInput)
    weight = forms.FloatField()
    balance = forms.DecimalField()
    check = forms.BooleanField()
    birthday =  forms.DateField(widget=forms.DateInput(attrs={'type': 'date'}))
    appointment = forms.CharField(widget=forms.DateInput(attrs={'type': 'datetime-local'}))
    CHOICES = [('S', 'Small'), ('M', 'Medium'), ('L', 'Large')]
    size = forms.ChoiceField(choices=CHOICES, widget=forms.RadioSelect)
    MEAL = [('P', 'Pepperoni'), ('M', 'Mashroom'), ('B', 'Beef')]
    pizza = forms.MultipleChoiceField(choices=MEAL, widget=forms.CheckboxSelectMultiple)
    file=forms.FileField(
        validators=[validators.FileExtensionValidator(allowed_extensions=['pdf, png'], message='.pdf .png only')]
    )

def len_check(value):
    if len(value) < 10:
        raise forms.ValidationError('Enter a value at last 10 chars')
    


class StudentData(forms.Form):
    name = forms.CharField(
        widget=forms.TextInput,
        # inbuild validators
        validators=[validators.MinLengthValidator(10, message='Enter at last 10 chars')]
    )
    
    email = forms.CharField(widget=forms.EmailInput,
        validators=[validators.EmailValidator(message='Enter Vaild Email')]
    )


    # --- custom validators -- 
    # def clean(self):
    #     cleaned_data = super().clean()
    #     valname = self.cleaned_data['name']
    #     valemail = self.cleaned_data['email']
    #     if len(valname) < 10:
    #         raise forms.ValidationError('Enter a name with at last 10 char')
    #     if '.com' not in valemail:
    #         raise forms.ValidationError('Your Email Must Contain .com')
    
    

class PasswordValidationForm(forms.Form):
    name = forms.CharField(widget=forms.TextInput)
    password = forms.CharField(widget=forms.PasswordInput)
    confirm_password = forms.CharField(widget=forms.PasswordInput)

    def clean(self):
        clean_data = super().clean()
        val_name = self.cleaned_data['name']
        val_pass = self.cleaned_data['password']
        val_conpass = self.cleaned_data['confirm_password']

        if val_pass != val_conpass:
            raise forms.ValidationError("Password doesn't matched")
        if len(val_name) < 10:
            raise forms.ValidationError("Name must be at last 10 chars")
        


# inbuild form from Model-Form 
# 1. import Student model form models.py 


class StudentForm(forms.ModelForm):
    
    class Meta: 
        model = Student
        fields = ("__all__")
        labels = {
            'name':'Student Name',
            'roll':'Student Roll'
        }
        widgets = {
            'name': forms.TextInput(),
        }
        help_texts = {
            'name': 'Write your full Name'
        }
        error_messages = {
            'name':{'required': 'Your name is required'}
        }

