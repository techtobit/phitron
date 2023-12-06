from django import forms

class contactForm(forms.Form):
    name = forms.CharField(label='Full Name: ', help_text='Total lenght must be within 60 Char',required=False, error_messages={'required': 'Please Enter Name'}, widget=forms.Textarea(attrs={'id': 'text_area', 'class': 'class1 class2', 'placeholder': 'Enter Your Name' },) )
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
    file=forms.FileField()


class StudentData(forms.Form):
    name = forms.CharField(widget=forms.TextInput)
    email = forms.CharField(widget=forms.EmailInput)

    def clean(self):
        cleaned_data = super().clean()
        valname = self.cleaned_data['name']
        valemail = self.cleaned_data['email']
        if len(valname) < 10:
            raise forms.ValidationError('Enter a name with at last 10 char')
        if '.com' not in valemail:
            raise forms.ValidationError('Your Email Must Contain .com')
    
    